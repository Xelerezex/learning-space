#include <iostream>
#include <iomanip>
#include <cmath>


int main() {
    double n, x, n_plus_one, r = 0;
    std::cin >> n; // Неотрицательное число n ≤ 20
    std::cin >> x; // Действительное число x
    while (n >= 0) {
        std::cin >> n_plus_one;
        r = r * x + n_plus_one;
        n--;
    }
    std::cout << r;
    return 0;
}
