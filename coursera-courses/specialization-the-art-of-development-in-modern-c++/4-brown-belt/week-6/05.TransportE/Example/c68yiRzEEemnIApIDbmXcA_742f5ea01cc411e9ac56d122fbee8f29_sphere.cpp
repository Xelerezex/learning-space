#include "sphere.h"

using namespace std;

namespace Sphere {
  const double PI = 3.1415926535;

  double ConvertDegreesToRadians(double degrees) {
    return degrees * PI / 180.0;
  }

  Point Point::FromDegrees(double latitude, double longitude) {
    return {
      ConvertDegreesToRadians(latitude),
      ConvertDegreesToRadians(longitude)
    };
  }

  const double EARTH_RADIUS = 6'371'000;

  double Distance(Point lhs, Point rhs) {
    lhs = Point::FromDegrees(lhs.latitude, lhs.longitude);
    rhs = Point::FromDegrees(rhs.latitude, rhs.longitude);
    return acos(
      sin(lhs.latitude) * sin(rhs.latitude)
      + cos(lhs.latitude) * cos(rhs.latitude) * cos(abs(lhs.longitude - rhs.longitude))
    ) * EARTH_RADIUS;
  }
}
