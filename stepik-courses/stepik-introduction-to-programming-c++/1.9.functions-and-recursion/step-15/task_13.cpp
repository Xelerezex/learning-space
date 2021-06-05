#include <iostream>

int MinNumberOfTry(int floor) {
    if (floor < 3) {
        return 1;
    } else {
        return MinNumberOfTry(floor - MinNumberOfTry(floor - 1)) + 1;
    }
}

int main() {
    int n;
    std::cin >> n;
    std::cout << MinNumberOfTry(n);
    return 0;
}
