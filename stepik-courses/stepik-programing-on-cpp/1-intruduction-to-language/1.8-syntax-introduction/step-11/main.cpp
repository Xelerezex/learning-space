#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    double discr, a1, a2;
    discr = (b * b) - (4 * a * c);
    if (discr >= 0){
        a1 = ((-b) + sqrt(discr)) / (2 * a);
        a2 = ((-b) - sqrt(discr)) / (2 * a);
        cout << a1 << " " << a2 << endl;
    } else {
        cout << "No real roots" << endl;
    }

    return 0;
}
