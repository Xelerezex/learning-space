#include <iostream>

using namespace std;

int main() {
    // put your code here
    double p, x, y, money, rub, kop;
    cin >> p >> x >> y;
    money = (100 * x + y) * (100 + p) / 100;
    rub = money / 100;
    kop = int(money) % 100;
    cout << int(rub) << " " << kop;
    return 0;
}
