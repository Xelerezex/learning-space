#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    double a, b, c;
    double r1, r2;
    const int one_root = 1;
    const int two_roots = 2;
    const int inf_roots = 3;
    const int no_roots = 0;

    cin >> a >> b >> c;

    if (a != 0) {
        double discr = b * b - 4 * a * c;
        if (discr > 0) {
            r1 = (-b - sqrt(discr)) / (2 * a);
            r2 = (-b + sqrt(discr)) / (2 * a);
            cout << two_roots << " " << min(r1, r2) << " " << max(r1, r2);
        } else if (discr == 0) {
            r1 = -b / (2 * a);
            cout << one_root << " " << r1;
        } else {
            cout << no_roots;
        }
    } else {
        if (b == 0 && c == 0) {
            cout << inf_roots;
        } else if (b != 0) {
            r1 = -c / b;
            cout << one_root << ' ' << r1;
        } else {
            cout << no_roots;
        }
    }
    return 0;
}
