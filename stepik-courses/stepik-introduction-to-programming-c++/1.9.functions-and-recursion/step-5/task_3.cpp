#include <iostream>

bool IsPointInSquare(double x, double y) {
    return (((-1 <= x) && (x <= 1)) && ((-1 <= y) && (y <= 1)));
}

int main() {
    double x, y;
    std::cin >> x >> y;
    (IsPointInSquare(x, y) == 1) ? std::cout << "YES" : std::cout << "NO";
    return 0;
}
