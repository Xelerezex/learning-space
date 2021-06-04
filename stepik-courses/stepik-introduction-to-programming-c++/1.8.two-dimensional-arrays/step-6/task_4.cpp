#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int elem;
            cin >> elem;
            a[i][j] = elem;
        }
    }
    int ch_n_1, ch_n_2;
    cin >> ch_n_1 >> ch_n_2;
    for (int i = 0; i < n; i++) {
        int tmp;
        tmp = a[i][ch_n_1];
        a[i][ch_n_1] = a[i][ch_n_2];
        a[i][ch_n_2] = tmp;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
