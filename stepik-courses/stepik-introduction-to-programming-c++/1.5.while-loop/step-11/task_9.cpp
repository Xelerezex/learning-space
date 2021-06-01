#include <iostream>

using namespace std;

int main() {
    // put your code here
    int n, first_max, second_max = -1;
    cin >> n;
    first_max = n;
    while (n != 0) {
        cin >> n;
        if (first_max <= n) {
            second_max = first_max;
            first_max = n;
        } else if (second_max < n)
            second_max = n;
    }
    cout << second_max;
    return 0;
}
