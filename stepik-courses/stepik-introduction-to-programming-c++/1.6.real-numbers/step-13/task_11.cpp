#include <iostream>
// Тут могло быть using namespace std;
int main() {
    double a, b, c, d, e, f, x, y;
    std::cin >> a >> b >> c >> d >> e >> f;
    x = (e * d - b * f) / (a * d - b * c);
    y = (a * f - c * e) / (a * d - b * c);
    std::cout << x << " " << y;
    return 0;
}
