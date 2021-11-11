#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int64_t max_dot_product(vector<int64_t> first, vector<int64_t> second) {    // ~ O(3·N·log(N)) -> O(N·log(N))
    if (first.size() != second.size()) {
        return -1;
    }
    int64_t result = 0;

    sort(first.begin(), first.end());           // O(N·log(N))
    sort(second.begin(), second.end());         // O(N·log(N))

    for (size_t it = 0; it < first.size(); ++it) {  // O(N)
        result += (first[it] * second[it]);
    }

    return result;
}

int main() {
    size_t n;
    std::cin >> n;
    vector<int64_t> a(n), b(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (size_t i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    std::cout << max_dot_product(a, b) << std::endl;
}
