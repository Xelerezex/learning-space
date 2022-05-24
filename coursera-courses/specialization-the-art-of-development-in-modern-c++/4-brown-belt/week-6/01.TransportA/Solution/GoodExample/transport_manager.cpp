#include "transport_manager.h"
#include "bus.h"
#include "graph.h"
#include "stop_manager.h"
#include "transport_manager_command.h"

#include <iterator>
#include <sstream>
#include <set>
#include <unordered_set>
#include <memory>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

void TransportManager::InitStop(const string& name) {
  if (!stop_idx.count(name) || (stop_idx.count(name) && stops_[stop_idx[name]].Name() != name)) {
    stops_.emplace_back(name);
    stop_idx[name] = stops_.size() - 1;
  }
}

void TransportManager::AddStop(const string& name, double latitude, double longitude, const unordered_map<string, unsigned int>& distances) {
  InitStop(name);

  size_t id = stop_idx[name];
  stops_[id].SetCoordinates(Coordinates{latitude, longitude});

  for (const auto& [stop_name, dist] : distances) {
    InitStop(stop_name);
    distances_[id][stop_idx[stop_name]] = dist;
    if (!distances_[stop_idx[stop_name]].count(id) || (distances_[stop_idx[stop_name]].count(id) && distances_[stop_idx[stop_name]][id] == 0)) {
      distances_[stop_idx[stop_name]][id] = dist;
    }
  }
}

void TransportManager::AddBus(const RouteNumber& bus_no, const std::vector<std::string>& stop_names, bool cyclic) {
  buses_[string{bus_no}] = cyclic ? BusRoute::CreateCyclicBusRoute(bus_no, stop_names)
    : BusRoute::CreateRawBusRoute(bus_no, stop_names);
}

std::pair<unsigned int, double> TransportManager::ComputeBusRouteLength(const RouteNumber& route_number) {
  if (!buses_.count(route_number)) {
    return {0, 0};
  }

  if (auto route_length = buses_[route_number].RouteLength(); route_length.has_value()) {
    return route_length.value();
  }

  unsigned int distance_road{0};
  double distance_direct{0.0};
  vector<const Stop*> bus_stops;
  for (const auto& stop_name : buses_[route_number].Stops()) {
    InitStop(stop_name);
    bus_stops.push_back(&stops_[stop_idx[stop_name]]);
  }

  for (size_t i = 0; i < bus_stops.size() - 1; ++i) {
    distance_direct += Coordinates::Distance(bus_stops[i]->StopCoordinates(),
                                             bus_stops[i + 1]->StopCoordinates());
    distance_road += distances_[stop_idx[bus_stops[i]->Name()]][stop_idx[bus_stops[i + 1]->Name()]];
  }

  buses_[route_number].SetRouteLength(distance_road, distance_direct);
  return {distance_road, distance_direct};
}

StopInfo TransportManager::GetStopInfo(const string& stop_name, size_t request_id) {
  if (!stop_idx.count(stop_name)) {
    return StopInfo{
      .request_id = request_id,
      .error_message = "not found",
    };
  }

  set<RouteNumber> buses_with_stop;
  for (const auto& bus : buses_) {
    if (bus.second.ContainsStop(stop_name)) {
        buses_with_stop.insert(bus.first);
    }
  }

  return StopInfo{
    .buses = vector<string>{begin(buses_with_stop), end(buses_with_stop)},
    .request_id = request_id,
  };
}

BusInfo TransportManager::GetBusInfo(const RouteNumber& bus_no, size_t request_id) {
  if (!buses_.count(bus_no)) {
    return BusInfo{
      .request_id = request_id,
      .error_message = "not found",
    };
  }

  const auto& bus = buses_.at(bus_no);
  const auto [road_length, direct_length] = ComputeBusRouteLength(bus_no);

  return BusInfo {
    .route_length = road_length,
    .request_id = request_id,
    .curvature = road_length / direct_length,
    .stop_count = bus.Stops().size(),
    .unique_stop_count = bus.UniqueStopNumber(),
  };
}

void TransportManager::CreateRoutes() {
  road_graph = make_unique<Graph::DirectedWeightedGraph<double>>(2 * stops_.size());

  for (size_t i = 0; i < stops_.size(); ++i) {
    road_graph->AddEdge(Graph::Edge<double>{
        .from = 2 * i,
        .to = 2 * i + 1,
        .weight = static_cast<double>(routing_settings_.bus_wait_time),
    });
    edge_description.push_back(WaitActivity{
      .type = "Wait",
      .time = routing_settings_.bus_wait_time,
      .stop_name = stops_[i].Name(),
    });
  }

  for (const auto& [bus_no, bus] : buses_) {
    const auto& bus_stops = bus.Stops();
    for (size_t i = 0; i < bus_stops.size(); ++i) {
      double time_sum{0.0};
      unsigned int span_count{0};
      for (size_t j = i + 1; j < bus_stops.size(); ++j) {
        time_sum += distances_[stop_idx[bus_stops[j - 1]]][stop_idx[bus_stops[j]]] / (routing_settings_.bus_velocity * 1000 / 60);
        road_graph->AddEdge(Graph::Edge<double>{
            .from = 2 * stop_idx[bus_stops[i]] + 1,
            .to = 2 * stop_idx[bus_stops[j]],
            .weight = time_sum
        });
        edge_description.push_back(BusActivity{
          .type = "Bus",
          .time = time_sum,
          .bus = bus_no,
          .span_count = ++span_count,
        });
      }
    }
  }

  router = make_unique<Graph::Router<double>>(*road_graph);
}

  RouteInfo TransportManager::GetRouteInfo(std::string from, std::string to, size_t request_id) {
    size_t from_id = 2 * stop_idx[from];
    size_t to_id = 2 * stop_idx[to];
    auto route_info = router->BuildRoute(from_id, to_id);

    if (!route_info.has_value()) {
      return {
        .request_id = request_id,
        .error_message = "not found",
      };
    }

    std::vector<std::variant<WaitActivity, BusActivity>> items;
    auto id = route_info.value().id;
    for (size_t i = 0; i < route_info.value().edge_count; ++i) {
      auto edge_id = router->GetRouteEdge(id, i);
      items.push_back(edge_description[edge_id]);
    }

    return {
      .request_id = request_id,
      .total_time = route_info.value().weight,
      .items = items,
    };
  }
