#include <iostream>

using namespace std;

int main() {
    // put your code here
    int A, B, N;
    cin >> A >> B >> N;
    cout << A * N + (B * N) / 100 << " " << B * N % 100;
    return 0;
}
