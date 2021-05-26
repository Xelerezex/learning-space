#include <iostream>
using namespace std;

int main()
{
    char c = '\0';
    char z = '\0';

    while (cin.get(c)) {
        if (c == ' ' and z == ' '){
            continue;
        }
        z = c;
        cout << c;
    }

    return 0;
}
