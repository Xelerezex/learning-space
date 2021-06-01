#include <iostream>

using namespace std;

int main() {
    // put your code here
    int a, tmp;
    cin >> a;
    if (a == 0) {
        cout << 0;
    } else {
        int fib_prev = 0, fib_next = 1, n = 1;
        while (fib_next <= a) {
            if (fib_next == a) {
                cout << n;
                break;
            }
            tmp = fib_next;
            fib_next = fib_prev + fib_next;
            fib_prev = tmp;
            n++;
        }
        if (fib_next > a) {
            cout << -1;
        }
    }
    return 0;
}
