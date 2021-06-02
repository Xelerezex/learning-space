#include <iostream>

using namespace std;
// Задача решается Методом Краммера, ради этого стоило ходитб на 1 курс на "Анал"
// (Аналитическая алгебра и линейная геометрия)
int main() {
    double a, b, c, d, e, f, det, detx, dety;
    cin >> a >> b >> c >> d >> e >> f;
    det = a * d - b * c;
    detx = e * d - b * f;
    dety = a * f - e * c;
    if (det == 0) {
        if (detx == 0 && dety == 0) {
            if (a == 0 && b == 0 && c == 0 && d == 0) {
                if (e == 0 && f == 0) cout << 5;
                else cout << 0;
            } else if (a == 0 && c == 0) {
                if (b == 0) cout << 4 << " " << f / d;
                else cout << 4 << " " << e / b;
            } else if (b == 0 && d == 0) {
                if (a == 0) cout << 3 << " " << f / c;
                else cout << 3 << " " << e / a;
            } else if (b == 0) cout << 1 << " " << -c / d << " " << f / d;
            else cout << 1 << " " << -a / b << " " << e / b;
        } else cout << 0;
    } else cout << 2 << " " << detx / det << " " << dety / det;

    return 0;
}
