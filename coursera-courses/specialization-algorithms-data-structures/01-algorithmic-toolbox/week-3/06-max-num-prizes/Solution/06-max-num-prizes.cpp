#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
    vector<int> summands;

    int diff = 0,
        number = 1;

    while (diff < n) {
        if (diff + number <= n) {
            summands.push_back(number);
            diff += number;
        } else {
            summands[summands.size() - 1] += n - diff;
            break;
        }
        ++number;
    }
    return summands;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> summands = optimal_summands(n);
    std::cout << summands.size() << '\n';
    for (size_t i = 0; i < summands.size(); ++i) {
        std::cout << summands[i] << ' ';
    }
}
