#include <iostream>

uint64_t EuclidGCD(uint64_t first, uint64_t second) {
    return (second == 0) ? first : EuclidGCD(second, first % second);
}

int main() {
    uint64_t first = 0, second = 0;
    std::cin >> first >> second;
    std::cout << EuclidGCD(first, second) << '\n';
}
