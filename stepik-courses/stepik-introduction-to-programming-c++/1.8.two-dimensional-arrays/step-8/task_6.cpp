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
    int k;
    cin >> k;
    for (int i = 0; i < (n - abs(k)); i++) {
        cout << (k > 0 ? a[i + k][i] : a[i][i - k]) << " ";
    }
    return 0;
}
