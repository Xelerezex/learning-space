#include <iostream>

using namespace std;

int main() {
    // put your code here
    int n, max, counter;
    cin >> n;
    max = n, counter = 0;
    while (n != 0) {
        if (max < n) {
            max = n, counter = 1;
        } else if (n == max) {
            counter++;
        }
        cin >> n;
    }
    cout << counter;
    return 0;
}
