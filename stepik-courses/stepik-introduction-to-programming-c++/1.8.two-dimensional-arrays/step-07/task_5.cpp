#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    bool token = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (n + 1 / 2); j++) {
            if (a[i][j] != a[j][i]) {
                token = !token;
                break;
            }
        }
        if (!token) {
            break;
        }
    }
    (token) ? cout << "YES" : cout << "NO";
    return 0;
}
