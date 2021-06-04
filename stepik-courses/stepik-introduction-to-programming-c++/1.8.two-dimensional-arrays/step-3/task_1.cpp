#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, maxxelem, maxi, maxj;
    bool token = true;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (token) {
                maxxelem = a[i][j];
                maxi = i;
                maxj = j;
                token = !token;
            } else if (maxxelem < a[i][j]) {
                maxxelem = a[i][j];
                maxi = i;
                maxj = j;
            }
        }
    }
    cout << maxi << " " << maxj;
    return 0;
}
