#include "stop_manager.h"

#include <cmath>
#include <utility>

using namespace std;

const long double Coordinates::PI = 3.1415926535;
const long double Coordinates::ONE_DEG = Coordinates::PI / 180;
const long double Coordinates::EARTH_RADIUS = 6'371'000;

Stop::Stop(string name, Coordinates coordinates)
  : name_(move(name))
  , coordinates_(move(coordinates))
{
}

long double Coordinates::Distance(const Coordinates& lhs, const Coordinates& rhs) {
  auto to_radians = [](long double degrees) -> long double { return Coordinates::ONE_DEG * degrees; };

  auto lhs_lat = to_radians(lhs.latitude); 
  auto lhs_long = to_radians(lhs.longitude); 
  auto rhs_lat = to_radians(rhs.latitude); 
  auto rhs_long = to_radians(rhs.longitude); 
    
  long double ans = acos(sin(lhs_lat) * sin(rhs_lat) +
                    cos(lhs_lat) * cos(rhs_lat) * cos(abs(lhs_long - rhs_long)));
  ans *= Coordinates::EARTH_RADIUS; 
  
  return ans; 
}
