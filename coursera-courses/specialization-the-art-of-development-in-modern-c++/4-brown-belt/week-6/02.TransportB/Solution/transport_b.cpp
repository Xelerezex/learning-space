#include <cmath>
#include <exception>
#include <iostream>
#include <optional>
#include <set>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <vector>

#include "test_runner.h"

using namespace std;

namespace {
const int EARTH_RADIUS = 6371e3;  // meters
const double PI = 3.1415926535;

vector<string> splitBy(string_view str, const string& sep = " ") {
  vector<string> result;
  while (!str.empty()) {
    auto pos = str.find(sep);
    result.push_back(string(str.substr(0, pos)));
    str.remove_prefix(pos != str.npos ? pos + sep.size() : str.size());
  }
  return result;
}

struct Stop {
  string name_ = "";
  double lat_ = 0.0;
  double lon_ = 0.0;
  set<string> buses_ = {};
};

double degToRad(double deg) {
  return deg * PI / 180;
}

double computeDistance(const Stop& lhs, const Stop& rhs) {
  auto lhsRadLat = degToRad(lhs.lat_);
  auto lhsRadLon = degToRad(lhs.lon_);
  auto rhsRadLat = degToRad(rhs.lat_);
  auto rhsRadLon = degToRad(rhs.lon_);

  return acos(sin(lhsRadLat) * sin(rhsRadLat) +
              cos(lhsRadLat) * cos(rhsRadLat) *
                  cos(abs(lhsRadLon - rhsRadLon))) *
         EARTH_RADIUS;
}

class BusRoute {
 public:
  BusRoute(const string& routeNumber, bool isRing, vector<string> stopNames)
      : number_(routeNumber),
        isRing_(isRing),
        stopNames_(move(stopNames)),
        length_() {}

  size_t stopsCount() const {
    size_t result;
    if (isRing_) {
      result = stopNames_.size();
    } else {
      result = stopNames_.size() + stopNames_.size() - 1;
    }
    return result;
  }

  size_t uniqueStopsCount() const {
    set<string> uniqueStops(stopNames_.begin(), stopNames_.end());
    return uniqueStops.size();
  }

  optional<double> routeLength() const { return length_; }

  const vector<string>& stopsNames() const { return stopNames_; }

  bool isRing() const { return isRing_; }

  string routeNumber() const { return number_; }

  void setLength(double length) { length_.emplace(length); }

 private:
  string number_;
  bool isRing_;
  vector<string> stopNames_;
  optional<double> length_;
};

using Stops = unordered_map<string, Stop>;
using Routes = unordered_map<string, BusRoute>;

class BusManager {
 public:
  BusManager(Stops stops, Routes routes)
      : stops_(move(stops)), routes_(move(routes)) {}

  string routeInfo(const string& routeNumber) {
    ostringstream out_stream;
    if (routes_.count(routeNumber)) {
      auto stops = routes_.at(routeNumber).stopsCount();
      auto uniqueStops = routes_.at(routeNumber).uniqueStopsCount();
      auto routeLength = routes_.at(routeNumber).routeLength();
      if (!routeLength) {
        auto length = computeRouteLength(routeNumber);
        routes_.at(routeNumber).setLength(length);
      }
      out_stream << "Bus " << routeNumber << ": " << stops
                 << " stops on route, " << uniqueStops << " unique stops, "
                 << *routes_.at(routeNumber).routeLength() << " route length";
    } else {
      out_stream << "Bus " << routeNumber << ": not found";
    }

    return out_stream.str();
  }

  string stopInfo(const string& stopName) {
    ostringstream out_stream;
    if (stops_.count(stopName)) {
      const auto& buses = stops_.at(stopName).buses_;
      if (buses.empty()) {
        out_stream << "Stop " << stopName << ": no buses";
      } else {
        out_stream << "Stop " << stopName << ": buses";
        for (const auto& bus : buses) {
          out_stream << " " << bus;
        }
      }
    } else {
      out_stream << "Stop " << stopName << ": not found";
    }
    return out_stream.str();
  }

 private:
  Stops stops_;
  Routes routes_;

  double computeRouteLength(string routeNumber) {
    auto stopsNames = routes_.at(routeNumber).stopsNames();
    double length = 0.0;
    for (size_t i = 0; i < stopsNames.size() - 1; ++i) {
      const auto& first = stops_.at(stopsNames[i]);
      const auto& second = stops_.at(stopsNames[i + 1]);
      length += computeDistance(first, second);
    }

    if (!routes_.at(routeNumber).isRing()) {
      length *= 2;
    }

    return length;
  }
};
}  // namespace

Stop buildStop(string_view str) {
  Stop stop;
  str.remove_prefix(str.find_first_not_of(" "));

  auto pos = str.find_first_of(":");
  stop.name_ = str.substr(0, pos);

  str.remove_prefix(pos + 2);
  pos = str.find_first_of(",");
  stop.lat_ = stod(string(str.substr(0, pos)));

  pos = str.find_first_of(" ");
  str.remove_prefix(++pos);
  stop.lon_ = stod(string(str.substr(0)));

  return stop;
}

BusRoute buildRoute(string_view str) {
  str.remove_prefix(str.find_first_not_of(" "));

  auto pos = str.find_first_of(":");
  string routeNumber = string(str.substr(0, pos));

  str.remove_prefix(pos + 2);

  string separator;
  bool isRing;
  pos = str.find("-");
  if (pos != str.npos) {
    separator = " - ";
    isRing = false;
  } else {
    separator = " > ";
    isRing = true;
  }
  auto stopsNames = splitBy(str, separator);

  return BusRoute(routeNumber, isRing, move(stopsNames));
}

BusManager buildDataBase(istream& inStream = cin) {
  Stops stops;
  Routes routes;

  int requestCnt = 0;
  inStream >> requestCnt;
  for (int i = 0; i < requestCnt; ++i) {
    string requestType;
    inStream >> requestType;
    string strToParse;
    getline(inStream, strToParse);
    if (requestType == "Stop") {
      auto stop = buildStop(strToParse);
      if (stops.count(stop.name_)) {
        stops[stop.name_].lat_ = stop.lat_;
        stops[stop.name_].lon_ = stop.lon_;
        stops[stop.name_].name_ = move(stop.name_);
      } else {
        stops[stop.name_] = move(stop);
      }
    } else if (requestType == "Bus") {
      auto busRoute = buildRoute(strToParse);
      auto routeNumber = busRoute.routeNumber();
      for (const auto& stopName : busRoute.stopsNames()) {
        stops[stopName].buses_.insert(routeNumber);
      }
      routes.insert({routeNumber, move(busRoute)});
    }
  }

  return {stops, routes};
}

string parseRequest(string_view str) {
  auto pos = str.find_first_not_of(" ");
  return string(str.substr(pos));
}

void processRequests(BusManager& manager,
                     istream& inStream = cin,
                     ostream& outStream = cout) {
  outStream.precision(6);
  int requestCnt = 0;
  inStream >> requestCnt;
  for (int i = 0; i < requestCnt; ++i) {
    string requestType;
    inStream >> requestType;
    string strToParse;
    getline(inStream, strToParse);
    if (requestType == "Bus") {
      outStream << manager.routeInfo(parseRequest(strToParse)) << endl;
    } else if (requestType == "Stop") {
      outStream << manager.stopInfo(parseRequest(strToParse)) << endl;
    }
  }
}

void testBuildStop() {
  string str = "Stop Tolstopaltsevo: 55.611087, 37.20829";
  auto pos = str.find_first_of(" ");
  auto stop = buildStop(str.substr(pos));

  cout << "stop name:" << stop.name_ << endl;
  cout << "stop latitude:" << stop.lat_ << endl;
  cout << "stop longitude:" << stop.lon_ << endl;
}

void testBuildRoute() {
  string str =
      "Bus 256: Biryulyovo Zapadnoye > Biryusinka > Universam > Biryulyovo "
      "Tovarnaya > Biryulyovo Passazhirskaya > Biryulyovo Zapadnoye";
  auto pos = str.find_first_of(" ");
  auto route = buildRoute(str.substr(pos));
  cout << "route number:" << route.routeNumber() << endl;
}

void testBuildDataBase() {
  string str =
      "10\n"
      "Stop Tolstopaltsevo: 55.611087, 37.20829\n"
      "Stop Marushkino: 55.595884, 37.209755\n"
      "Bus 256: Biryulyovo Zapadnoye > Biryusinka > Universam > Biryulyovo "
      "Tovarnaya > Biryulyovo Passazhirskaya > Biryulyovo Zapadnoye\n"
      "Bus 750: Tolstopaltsevo - Marushkino - Rasskazovka\n"
      "Stop Rasskazovka: 55.632761, 37.333324\n"
      "Stop Biryulyovo Zapadnoye: 55.574371, 37.6517\n"
      "Stop Biryusinka: 55.581065, 37.64839\n"
      "Stop Universam: 55.587655, 37.645687\n"
      "Stop Biryulyovo Tovarnaya: 55.592028, 37.653656\n"
      "Stop Biryulyovo Passazhirskaya: 55.580999, 37.659164\n";
  istringstream in_stream(str);
  auto manager = buildDataBase(in_stream);
}

void testProcessRequests() {
  string str =
      "10\n"
      "Stop Tolstopaltsevo: 55.611087, 37.20829\n"
      "Stop Marushkino: 55.595884, 37.209755\n"
      "Bus 256: Biryulyovo Zapadnoye > Biryusinka > Universam > Biryulyovo "
      "Tovarnaya > Biryulyovo Passazhirskaya > Biryulyovo Zapadnoye\n"
      "Bus 750: Tolstopaltsevo - Marushkino - Rasskazovka\n"
      "Stop Rasskazovka: 55.632761, 37.333324\n"
      "Stop Biryulyovo Zapadnoye: 55.574371, 37.6517\n"
      "Stop Biryusinka: 55.581065, 37.64839\n"
      "Stop Universam: 55.587655, 37.645687\n"
      "Stop Biryulyovo Tovarnaya: 55.592028, 37.653656\n"
      "Stop Biryulyovo Passazhirskaya: 55.580999, 37.659164\n"
      "3\n"
      "Bus 256\n"
      "Bus 750\n"
      "Bus 751\n";
  istringstream in_stream(str);

  auto manager = buildDataBase(in_stream);
  ostringstream out_stream;
  processRequests(manager, in_stream, out_stream);

  string result =
      "Bus 256: 6 stops on route, 5 unique stops, 4371.02 route length\n"
      "Bus 750: 5 stops on route, 3 unique stops, 20939.5 route length\n"
      "Bus 751: not found\n";
  ASSERT_EQUAL(result, out_stream.str());
}

void testComputeDistance() {
  vector<Stop> stops = {Stop{"Tolstopaltsevo", 55.611087, 37.20829},
                        Stop{"Marushkino", 55.595884, 37.209755},
                        Stop{"Rasskazovka", 55.632761, 37.333324}};
  double length = 0.0;
  for (size_t i = 0; i < stops.size() - 1; ++i) {
    length += computeDistance(stops[i], stops[i + 1]);
  }

  length *= 2;
  cout << "length " << length << endl;
}

void testStopRequests() {
  string str =
      "13\n"
      "Stop Tolstopaltsevo: 55.611087, 37.20829\n"
      "Stop Marushkino: 55.595884, 37.209755\n"
      "Bus 256: Biryulyovo Zapadnoye > Biryusinka > Universam > Biryulyovo "
      "Tovarnaya > Biryulyovo Passazhirskaya > Biryulyovo Zapadnoye\n"
      "Bus 750: Tolstopaltsevo - Marushkino - Rasskazovka\n"
      "Stop Rasskazovka: 55.632761, 37.333324\n"
      "Stop Biryulyovo Zapadnoye: 55.574371, 37.6517\n"
      "Stop Biryusinka: 55.581065, 37.64839\n"
      "Stop Universam: 55.587655, 37.645687\n"
      "Stop Biryulyovo Tovarnaya: 55.592028, 37.653656\n"
      "Stop Biryulyovo Passazhirskaya: 55.580999, 37.659164\n"
      "Bus 828: Biryulyovo Zapadnoye > Universam > Rossoshanskaya ulitsa > "
      "Biryulyovo Zapadnoye\n"
      "Stop Rossoshanskaya ulitsa: 55.595579, 37.605757\n"
      "Stop Prazhskaya: 55.611678, 37.603831\n"
      "6\n"
      "Bus 256\n"
      "Bus 750\n"
      "Bus 751\n"
      "Stop Samara\n"
      "Stop Prazhskaya\n"
      "Stop Biryulyovo Zapadnoye\n";
  istringstream in_stream(str);

  auto manager = buildDataBase(in_stream);
  ostringstream out_stream;
  processRequests(manager, in_stream, out_stream);

  cout << out_stream.str() << endl;
}

int main() {
  auto manager = buildDataBase();
  processRequests(manager);

  //  TestRunner tr;
  //  RUN_TEST(tr, testStopRequests);
  //  RUN_TEST(tr, testProcessRequests);
  //  RUN_TEST(tr, testBuildStop);
  //  RUN_TEST(tr, testBuildRoute);
  //  RUN_TEST(tr, testBuildDataBase);
  //  RUN_TEST(tr, testComputeDistance);

  return 0;
}
