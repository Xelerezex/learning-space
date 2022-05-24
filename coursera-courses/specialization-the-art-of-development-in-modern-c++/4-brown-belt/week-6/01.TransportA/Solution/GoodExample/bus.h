#pragma once

#include "stop_manager.h"

#include <cstddef>
#include <optional>
#include <vector>
#include <string>
#include <unordered_set>
#include <memory>
#include <utility>

class BusRoute {
public:
  using RouteNumber = std::string;

  BusRoute(RouteNumber bus_no, std::vector<std::string> stop_names);
  BusRoute() = default;

  RouteNumber Number() const { return number_; }
  const auto& Stops() const { return stops_; }
  size_t UniqueStopNumber() const { return stop_names_.size(); }
  std::optional<std::pair<double, double>> RouteLength() { return route_length_; }
  bool ContainsStop(const std::string& stop_name) const { return stop_names_.count(stop_name); }

  void SetRouteLength(size_t road_length, double direct_length) { route_length_ = {road_length, direct_length}; }

  static BusRoute CreateRawBusRoute(RouteNumber bus_no, const std::vector<std::string>& stop_names);
  static BusRoute CreateCyclicBusRoute(RouteNumber bus_no, const std::vector<std::string>& stop_names);
private:
  RouteNumber number_;
  std::vector<std::string> stops_;
  std::unordered_set<std::string> stop_names_;
  std::optional<std::pair<size_t, double>> route_length_;
};
