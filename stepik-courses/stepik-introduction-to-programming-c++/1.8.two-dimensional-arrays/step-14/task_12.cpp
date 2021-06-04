#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows, columns, num = 1;
    cin >> rows >> columns;
    vector<vector<int>> snake(rows, vector<int>(columns));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if ((i + j) % 2 == 0) {
                snake[i][j] = num;
                num++;
            } else {
                snake[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%4d", snake[i][j]);
        }
        cout << "\n";
    }
    return 0;
}
