#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<char>> a(n, vector<char>(n, '.'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == j) ||
                ((i + j) == (n - 1)) ||
                (i == (n / 2)) ||
                (j == (n / 2))) {
                a[i][j] = '*';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
