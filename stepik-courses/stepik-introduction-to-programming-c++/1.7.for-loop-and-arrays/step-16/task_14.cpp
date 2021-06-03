#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> not_ninepins(n);
    for (int i = 0; i < n; i++) {
        not_ninepins[i] = 1;
    }
    for (int i = 0; i < k; i++) {
        int from, to;
        cin >> from >> to;
        for (int j = from - 1; j < to; j++) {
            not_ninepins[j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (not_ninepins[i] == 1) {
            cout << "I";
        } else {
            cout << ".";
        }
    }
    return 0;
}
