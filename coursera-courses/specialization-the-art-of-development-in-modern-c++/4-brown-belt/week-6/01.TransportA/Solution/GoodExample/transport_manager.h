#pragma once

#include "stop_manager.h"
#include "bus.h"
#include "transport_manager_command.h"
#include "graph.h"
#include "router.h"

#include <string_view>
#include <variant>
#include <vector>
#include <unordered_map>
#include <memory>
#include <utility>

struct RoutingSettings{
  unsigned int bus_wait_time;
  double bus_velocity;
};

class TransportManager {
public:
  using RouteNumber = BusRoute::RouteNumber;

  TransportManager(RoutingSettings routing_settings)
    : routing_settings_(std::move(routing_settings))
  {
  }

  void AddStop(const std::string& name, double latitude, double longitude, const std::unordered_map<std::string, unsigned int>& distances);
  void AddBus(const RouteNumber& route_number, const std::vector<std::string>& stop_names, bool cyclic);

  std::pair<unsigned int, double> ComputeBusRouteLength(const RouteNumber& route_number);
  StopInfo GetStopInfo(const std::string& stop_name, size_t request_id);
  BusInfo GetBusInfo(const RouteNumber& route_number, size_t request_id);

  void CreateRoutes();
  RouteInfo GetRouteInfo(std::string from, std::string to, size_t request_id);
private:
  std::unordered_map<std::string, size_t> stop_idx;
  std::vector<Stop> stops_;
  std::unordered_map<size_t, std::unordered_map<size_t, unsigned int>> distances_;
  std::unordered_map<RouteNumber, BusRoute> buses_;
  RoutingSettings routing_settings_;
  std::unique_ptr<Graph::DirectedWeightedGraph<double>> road_graph{nullptr};
  std::unique_ptr<Graph::Router<double>> router{nullptr};
  std::vector<std::variant<WaitActivity, BusActivity>> edge_description;

  void InitStop(const std::string& name);
};

