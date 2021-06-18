#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    /* Вспинаем 7 класс, а то и 5:
    "Признак существования треугольника"
    Сумма длин любых двух сторон треугольника должна быть больше длины третьей стороны.
    */
    if (((a + b) > c) && ((a + c) > b) && ((b + c) > a)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
