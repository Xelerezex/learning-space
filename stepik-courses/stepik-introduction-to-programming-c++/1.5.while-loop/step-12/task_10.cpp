#include <iostream>

using namespace std;

int main() {
    // put your code here
    int n_minus_one = 1, n_minus_two = 0, n, tmp, counter = 0;
    cin >> n;
    while (counter != n) {
        tmp = n_minus_one;
        n_minus_one += n_minus_two;
        n_minus_two = tmp;
        counter++;
    }
    cout << n_minus_two;
    return 0;
}
