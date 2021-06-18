#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    short n;
    cin >> n;
    vector<pair<int, int>> list_mark(n);
    for (pair<int, int> &num : list_mark) {
        cin >> num.second >> num.first;
        num.first *= -1;
    }
    sort(list_mark.begin(), list_mark.end());

    for (pair<int, int> &num : list_mark) {
        cout << num.second << " " << -1 * num.first << endl;
    }
    return 0;
}
