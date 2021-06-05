#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> seq(n);
    for (int i = 0; i < n; i++) {
        std::cin >> seq[i];
    }
    sort(seq.begin(), seq.end());
    for (auto elem : seq) {
        std::cout << elem << " ";
    }
    return 0;
}
