#include <iostream>

using namespace std;

int main() {
    // put your code here
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    // Будем считать что N меньшая из сторон бассейна
    if (N > M) {
        M = N + M;
        N = M - N;
        M = M - N;
    }
    if ((N - X) < (M - Y)) {
        if ((N - X) < X) {
            if ((N - X) < Y) {
                cout << N - X;
            } else {
                cout << Y;
            }
        } else if (X < Y) {
            cout << X;
        } else {
            cout << Y;
        }
    } else if (Y < (M - Y)) {
        if (Y < X) {
            cout << Y;
        } else {
            cout << X;
        }
    } else if ((M - Y) < X) {
        cout << M - Y;
    } else {
        cout << X;
    }
    return 0;
}
