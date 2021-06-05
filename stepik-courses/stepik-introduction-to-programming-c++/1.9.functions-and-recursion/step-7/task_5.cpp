#include <iostream>
#include <cmath>

bool IsPointInCircle(double x, double y, double xc, double yc, double r) {
    return pow((x - xc), 2) + pow((y - yc), 2) <= pow(r, 2);
}

int main() {
    double x, y, xc, yc, r;
    std::cin >> x >> y >> xc >> yc >> r;
    std::cout << (IsPointInCircle(x, y, xc, yc, r) ? "YES" : "NO");
    return 0;
}
