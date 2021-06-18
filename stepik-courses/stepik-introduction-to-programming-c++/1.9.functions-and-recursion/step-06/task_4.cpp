#include <iostream>
#include <cmath>

bool IsPointInSquare(double x, double y) {
    return std::abs(x) + std::abs(y) <= 1;
}

int main() {
    double x, y;
    std::cin >> x >> y;
    std::cout << (IsPointInSquare(x, y) ? "YES" : "NO");
    return 0;
}
