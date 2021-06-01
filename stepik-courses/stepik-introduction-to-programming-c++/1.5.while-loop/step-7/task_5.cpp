#include <iostream>

using namespace std;

int main() {
    // put your code here
    int n, counter;
    counter = 0;
    cin >> n;
    while (n != 0) {
        counter++;
        cin >> n;
    }
    cout << counter;
    return 0;
}
