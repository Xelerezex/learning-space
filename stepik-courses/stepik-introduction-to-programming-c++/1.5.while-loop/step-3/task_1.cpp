#include <iostream>

using namespace std;

int main() {
    // put your code here
    int i, n;
    i = 1;
    cin >> n;
    while ((i * i) <= n) {
        cout << (i * i) << " ";
        i++;
    }
    return 0;
}
