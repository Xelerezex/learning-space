#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, counter = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < v.size(); i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); i++) {
        if (v[i] != v[i - 1]) {
            counter++;
        }
    }
    cout << counter + 1;
    return 0;
}
