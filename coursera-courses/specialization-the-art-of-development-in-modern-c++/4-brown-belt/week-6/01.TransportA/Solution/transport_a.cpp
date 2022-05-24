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

struct Station {
  string name_ = "";
  double lat_ = 0.0;
  double lon_ = 0.0;
};

double degToRad(double deg) {
  return deg * PI / 180;
}

double computeDistance(const Station& lhs, const Station& rhs) {
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
  BusRoute(const string& routeNumber, bool isRing, vector<string> stationNames)
      : number_(routeNumber),
        isRing_(isRing),
        stationNames_(move(stationNames)),
        length_() {}

  size_t stationsCount() const {
    size_t result;
    if (isRing_) {
      result = stationNames_.size();
    } else {
      result = stationNames_.size() + stationNames_.size() - 1;
    }
    return result;
  }

  size_t uniqueStationsCount() const {
    set<string> uniqueStations(stationNames_.begin(), stationNames_.end());
    return uniqueStations.size();
  }

  optional<double> routeLength() const { return length_; }

  const vector<string>& stationNames() const { return stationNames_; }

  bool isRing() const { return isRing_; }

  string routeNumber() const { return number_; }

  void setLength(double length) { length_.emplace(length); }

 private:
  string number_;
  bool isRing_;
  vector<string> stationNames_;
  optional<double> length_;
};

using Stations = unordered_map<string, Station>;
using Routes = unordered_map<string, BusRoute>;

class BusManager {
 public:
  BusManager(Stations stations, Routes routes)
      : stations_(move(stations)), routes_(move(routes)) {}

  string routeInfo(const string& routeNumber) {
    ostringstream out_stream;
    if (routes_.count(routeNumber)) {
      auto stops = routes_.at(routeNumber).stationsCount();
      auto uniqueStops = routes_.at(routeNumber).uniqueStationsCount();
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

 private:
  Stations stations_;
  Routes routes_;

  double computeRouteLength(string routeNumber) {
    auto stationNames = routes_.at(routeNumber).stationNames();
    double length = 0.0;
    for (size_t i = 0; i < stationNames.size() - 1; ++i) {
      const auto& first = stations_.at(stationNames[i]);
      const auto& second = stations_.at(stationNames[i + 1]);
      length += computeDistance(first, second);
    }

    if (!routes_.at(routeNumber).isRing()) {
      length *= 2;
    }

    return length;
  }
};
}  // namespace

Station buildStation(string_view str) {
  Station station;
  str.remove_prefix(str.find_first_not_of(" "));

  auto pos = str.find_first_of(":");
  station.name_ = str.substr(0, pos);

  str.remove_prefix(pos + 2);
  pos = str.find_first_of(",");
  station.lat_ = stod(string(str.substr(0, pos)));

  pos = str.find_first_of(" ");
  str.remove_prefix(++pos);
  station.lon_ = stod(string(str.substr(0)));

  return station;
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
  auto stationNames = splitBy(str, separator);

  return BusRoute(routeNumber, isRing, move(stationNames));
}

BusManager buildDataBase(istream& inStream = cin) {
  Stations stations;
  Routes routes;

  int requestCnt = 0;
  inStream >> requestCnt;
  for (int i = 0; i < requestCnt; ++i) {
    string requestType;
    inStream >> requestType;
    if (requestType == "Stop") {
      string strToParse;
      getline(inStream, strToParse);
      auto station = buildStation(strToParse);
      stations[station.name_] = move(station);
    } else if (requestType == "Bus") {
      string strToParse;
      getline(inStream, strToParse);
      auto busRoute = buildRoute(strToParse);
      routes.insert({busRoute.routeNumber(), move(busRoute)});
    }
  }

  return {stations, routes};
}

string parseRequest(string_view str) {
  auto pos = str.find_first_of(" ");
  return string(str.substr(++pos));
}

void processRequests(BusManager& manager,
                     istream& inStream = cin,
                     ostream& outStream = cout) {
  outStream.precision(6);
  int requestCnt = 0;
  inStream >> requestCnt;
  for (int i = 0; i < requestCnt; ++i) {
    string strToParse;
    getline(inStream, strToParse);
    if (strToParse.empty()) {
      getline(inStream, strToParse);
    }
    outStream << manager.routeInfo(parseRequest(strToParse)) << endl;
  }
}

void testBuildStation() {
  string str = "Stop Tolstopaltsevo: 55.611087, 37.20829";
  auto pos = str.find_first_of(" ");
  auto station = buildStation(str.substr(pos));

  cout << "station name:" << station.name_ << endl;
  cout << "station latitude:" << station.lat_ << endl;
  cout << "station longitude:" << station.lon_ << endl;
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
  vector<Station> stations = {Station{"Tolstopaltsevo", 55.611087, 37.20829},
                              Station{"Marushkino", 55.595884, 37.209755},
                              Station{"Rasskazovka", 55.632761, 37.333324}};
  double length = 0.0;
  for (size_t i = 0; i < stations.size() - 1; ++i) {
    length += computeDistance(stations[i], stations[i + 1]);
  }

  length *= 2;
  cout << "length " << length << endl;
}

int main() {
  auto manager = buildDataBase();
  processRequests(manager);

  //  TestRunner tr;
  //  RUN_TEST(tr, testProcessRequests);
  //  RUN_TEST(tr, testBuildStation);
  //  RUN_TEST(tr, testBuildRoute);
  //  RUN_TEST(tr, testBuildDataBase);
  //  RUN_TEST(tr, testComputeDistance);

  return 0;
}
