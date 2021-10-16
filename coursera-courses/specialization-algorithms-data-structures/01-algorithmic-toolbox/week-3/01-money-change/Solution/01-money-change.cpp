#include <iostream>

unsigned change(unsigned coins) {
    unsigned count = 0;

    while (coins > 0) {
        if (coins >= 10) {
            coins -= 10;
            ++count;
        } else if (coins >= 5) {
            coins -= 5;
            ++count;
        } else {
            coins -= 1;
            ++count;
        }
    }

    return count;
}

int main() {
    unsigned coins = 0;
    std::cin >> coins;
    std::cout << change(coins) << std::endl;
}
