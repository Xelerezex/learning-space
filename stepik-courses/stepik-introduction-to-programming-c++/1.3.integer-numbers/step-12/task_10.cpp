#include <iostream>

using namespace std;

int main() {
    int n, hours, minutes, seconds;
    cin >> n;

    hours = n / 3600;
    n -= hours * 3600;

    minutes = n / 60;
    n -= minutes * 60;

    seconds = n;

    cout << hours % 24 << ':';
    cout << minutes / 10 << minutes % 10 << ':';
    cout << seconds / 10 << seconds % 10;
    return 0;
}
