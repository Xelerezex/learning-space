#include <iostream>

using namespace std;

double power(double a, int n) {
    if (n == 0) {
        return 1;
    } else if (n % 2 == 0) {
        return power(a * a, n / 2);
    } else {
        return a * power(a * a, n / 2);
    }
}

int main() {
    double a;
    int n;
    cin >> a >> n;
    cout << power(a, n);
    return 0;
}
