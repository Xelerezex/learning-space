#pragma once

#include <string>
#include <string_view>

struct Coordinates {
public:
  long double latitude;
  long double longitude;

  static long double Distance(const Coordinates& lhs, const Coordinates& rhs);

private:
  static const long double PI;
  static const long double ONE_DEG;
  static const long double EARTH_RADIUS;
};

struct Stop {
public:
  Stop(std::string name, Coordinates coordinates = {});
  Stop() = default;
  std::string Name() const { return name_; }
  Coordinates StopCoordinates() const { return coordinates_; }
  void SetCoordinates(Coordinates coordinates) { coordinates_ = coordinates; }

private:
  std::string name_;
  Coordinates coordinates_;
};

