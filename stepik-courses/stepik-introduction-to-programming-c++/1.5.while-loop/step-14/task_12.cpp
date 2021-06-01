#include <iostream>

using namespace std;

int main() {
    int n, max = 1, prev_N, prev_max = -1;
    cin >> n;
    while (n != 0) {
        prev_N = n;
        cin >> n;
        if (prev_N == n) {
            max++;
        } else if (prev_max < max) {
            prev_max = max;
            max = 1;
        } else {
            max = 1;
        }
    }
    if (prev_max > max) {
        cout << prev_max;
    } else {
        cout << max;
    }
    return 0;
}
