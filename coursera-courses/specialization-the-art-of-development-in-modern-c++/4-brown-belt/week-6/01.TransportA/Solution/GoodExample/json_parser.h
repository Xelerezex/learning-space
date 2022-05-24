#pragma once

#include "transport_manager_command.h"

#include <memory>
#include <string_view>
#include <iostream>
#include <vector>

namespace JsonArgs {

TransportManagerCommands ReadCommands(std::istream& s);
void PrintResults(const std::vector<StopInfo>& stop_info, const std::vector<BusInfo>& bus_info, const std::vector<RouteInfo>& route_data, std::ostream& output);

} // namespace JsonArgs 
