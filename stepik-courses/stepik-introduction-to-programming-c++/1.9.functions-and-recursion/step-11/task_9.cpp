#include <iostream>
#include <cmath>

using namespace std;

int MinDivisor(int n) {
    if (n % 2 == 0) {
        return 2;
    }
    for (int i = 3, isqrt = sqrt(n); i <= isqrt; i += 2)
        if (n % i == 0) {
            return i;
        }
    return n;
}

bool IsPrime(int n) {
    return MinDivisor(n) == n;
}

int main() {
    int n;
    cin >> n;
    cout << (IsPrime(n) ? "YES" : "NO");
    return 0;
}
