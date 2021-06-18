#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int foot_size, footwear_amount, counter = 0;
    std::cin >> foot_size >> footwear_amount;
    std::vector<int> footwear(footwear_amount);
    for (int i = 0; i < footwear_amount; i++) {
        std::cin >> footwear[i];
    }
    sort(footwear.begin(), footwear.end());
    for (auto boots_size : footwear) {
        if (foot_size <= boots_size && counter == 0) {
            foot_size = boots_size;
            counter++;
        } else if (boots_size - foot_size >= 3) {
            foot_size = boots_size;
            counter++;
        }
    }
    std::cout << counter;
    return 0;
}
