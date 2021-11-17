#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

template <typename RandomIt, typename Value>
RandomIt my_binary_search(RandomIt first, RandomIt last, Value element) {
    RandomIt save_end = last;

    while (first != last) {
        RandomIt middle = first + ((last - first) / 2);
        //cerr << *middle << endl;
        if (element < *middle) {
            last = middle;
        } else if (element > *middle) {
            first = ++middle;
        } else {
            return middle;
        }
    }

    return save_end;
}


vector<int> bunch_of_search(const vector<int> data, const vector<int> &to_find) {
    vector<int> temporary;
    for (const auto &element : to_find) {
        if (my_binary_search(data.begin(), data.end(), element) == data.end()) {
            temporary.push_back(-1);
        } else {
            temporary.push_back(distance(data.begin(),
                                         my_binary_search(data.begin(), data.end(), element))
                                );
        }
    }
    return temporary;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    int m;
    std::cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }

    for (const auto &item : bunch_of_search(a, b)) {
        std::cout << item << " ";
    }


}
