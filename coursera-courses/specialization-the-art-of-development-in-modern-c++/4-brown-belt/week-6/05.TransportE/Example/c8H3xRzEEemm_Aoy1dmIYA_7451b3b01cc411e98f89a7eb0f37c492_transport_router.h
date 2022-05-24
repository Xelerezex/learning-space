#pragma once

#include "descriptions.h"
#include "graph.h"
#include "json.h"
#include "router.h"

#include <memory>
#include <unordered_map>
#include <vector>

class TransportRouter {
private:
  using BusGraph = Graph::DirectedWeightedGraph<double>;
  using Router = Graph::Router<double>;

public:
  TransportRouter(const Descriptions::StopsDict& stops_dict,
                  const Descriptions::BusesDict& buses_dict,
                  const Json::Dict& routing_settings_json);

  struct RouteInfo {
    double total_time;

    struct BusItem {
      std::string bus_name;
      double time;
      size_t span_count;
    };
    struct WaitItem {
      std::string stop_name;
      double time;
    };

    using Item = std::variant<BusItem, WaitItem>;
    std::vector<Item> items;
  };

  std::optional<RouteInfo> FindRoute(const std::string& stop_from, const std::string& stop_to) const;

private:
  struct RoutingSettings {
    int bus_wait_time;  // in minutes
    double bus_velocity;  // km/h
  };

  static RoutingSettings MakeRoutingSettings(const Json::Dict& json);

  void FillGraphWithStops(const Descriptions::StopsDict& stops_dict);

  void FillGraphWithBuses(const Descriptions::StopsDict& stops_dict,
                          const Descriptions::BusesDict& buses_dict);

  struct StopVertexIds {
    Graph::VertexId in;
    Graph::VertexId out;
  };
  struct VertexInfo {
    std::string stop_name;
  };

  struct BusEdgeInfo {
    std::string bus_name;
    size_t span_count;
  };
  struct WaitEdgeInfo {};
  using EdgeInfo = std::variant<BusEdgeInfo, WaitEdgeInfo>;

  RoutingSettings routing_settings_;
  BusGraph graph_;
  std::unique_ptr<Router> router_;
  std::unordered_map<std::string, StopVertexIds> stops_vertex_ids_;
  std::vector<VertexInfo> vertices_info_;
  std::vector<EdgeInfo> edges_info_;
};
