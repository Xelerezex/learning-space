#include <iostream>

using namespace std;

int main() {
    int p, x, y, k;
    cin >> p >> x >> y >> k;
    y += x * 100;
    while (k--) {
        y += y * p / 100;
    }
    cout << y / 100 << " " << y % 100;
    return 0;
}
