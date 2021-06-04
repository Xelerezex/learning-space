#include <iostream>
#include <vector>

using namespace std;

int main() {
    // put your code here
    int rows, columns, num = 1;
    cin >> rows >> columns;
    vector<vector<int>> snake(rows, vector<int>(columns));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (i % 2 == 0) {
                snake[i][j] = num;
            } else {
                snake[i][columns - j - 1] = num;
            }
            num++;
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
