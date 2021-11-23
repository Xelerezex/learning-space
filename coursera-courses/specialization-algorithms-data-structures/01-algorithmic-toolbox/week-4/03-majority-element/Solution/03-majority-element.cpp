#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using std::max_element;
using std::vector;
using std::pair;
using std::map;
using std::cin;
using std::cout;

int get_majority_element(vector<int> &input) {
    map<int, int> hash;

    for (auto &item : input) {
        if (auto it = hash.find(item); it == hash.end()) {
            hash[item] = 1;
        } else {
            hash[item] += 1;
        }
    }

    int maxn = max_element(hash.begin(), hash.end(),
        [] (pair<int, int> lhs, pair<int, int> rhs) {
            return lhs.second < rhs.second;
        }
    )->second;

    // cerr << hash << endl;
    return ((input.size() / 2) < maxn) ? 1 : 0 ;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (size_t i = 0; i < a.size(); ++i) {
        cin >> a[i];
    }

    cout << get_majority_element(a) << '\n';
}
