#include <iostream>

using namespace std;

int main() {
    // put your code here
    int N;
    cin >> N;
    cout << N / 100 + (N / 10) % 10 + N % 10;
    return 0;
}
