#include <iostream>

using namespace std;

int main() {
    // put your code here
    int N, M, K;
    cin >> N >> M >> K;
    if (((N * M) > K) && ((K % N == 0) || (K % M == 0))) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
