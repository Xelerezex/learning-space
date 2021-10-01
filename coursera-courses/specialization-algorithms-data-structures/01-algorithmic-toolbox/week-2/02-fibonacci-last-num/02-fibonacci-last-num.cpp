#include <iostream>
#include <vector>

int Fibonacci(int number) {
    std::vector<int> output;
    output.push_back(0);
    output.push_back(1);

    for (int i = 2; i <= number; ++i) {
        int item = ((output[i - 1]) + (output[i - 2])) % 10;
        output.push_back(item);
    }

    return output[number];
}

int main() {
    int number = 0;
    std::cin >> number;
    std::cout << Fibonacci(number) << '\n';
}
