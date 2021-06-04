#include <iostream>
#include <vector>

using namespace std;

int main() {
    // put your code here
    int rows, columns, num = 1;
    cin >> rows >> columns;
    vector<vector<int>> not_snake(rows, vector<int>(columns));
    for (int i = 0; i < (rows + columns - 1); i++) {
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < columns; k++) {
                if ((j == (i - k)) || (k == (i - j))) {
                    not_snake[j][k] = num;
                    num++;
                }
            }
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%4d", not_snake[i][j]);
        }
        cout << "\n";
    }
    return 0;
}
