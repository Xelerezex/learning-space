#include <iostream>

using namespace std;

int main() {
    // put your code here
    int n, i;
    i = 2;
    cin >> n;
    while ((n % i) != 0) {
        i++;
    }
    cout << i;
    return 0;
}
