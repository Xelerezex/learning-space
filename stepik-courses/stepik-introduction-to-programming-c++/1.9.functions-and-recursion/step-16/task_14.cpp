#include <iostream>

using namespace std;

bool isSafe(int &, int &, int[]);

int placing(int, int &, int[]);

int main() {
    int N;
    cin >> N;
    int position[N] = {};
    cout << placing(0, N, position);
}

bool isSafe(int &row_position, int &queen_number, int position[]) {
    for (int i = 0; i < queen_number; i++) {
        int prev_row_pos = position[i];

        if (prev_row_pos == row_position || abs(prev_row_pos - row_position) == abs(i - queen_number)) {
            return false;
        }
    }

    return true;
}


int placing(int row, int &N, int position[]) {
    if (row == N) {
        return 1;
    }

    int num_of_comb = 0;

    for (int i = 0; i < N; i++) {
        if (isSafe(i, row, position)) {
            position[row] = i;
            num_of_comb += placing(row + 1, N, position);
        }
    }
    return num_of_comb;
}
