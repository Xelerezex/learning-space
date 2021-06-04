#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows, columns;
    cin >> rows >> columns;
    vector<vector<int>> spiral(rows, vector<int>(columns));
    int i = 0, j = -1, count = 0;
    while (count < rows * columns) {
        while (j < columns - 1 && !spiral[i][j + 1])
            spiral[i][++j] = ++count;
        while (i < rows - 1 && !spiral[i + 1][j])
            spiral[++i][j] = ++count;
        while (j > 0 && !spiral[i][j - 1])
            spiral[i][--j] = ++count;
        while (i > 0 && !spiral[i - 1][j])
            spiral[--i][j] = ++count;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%4d", spiral[i][j]);
        }
        cout << "\n";
    }
    return 0;
}
