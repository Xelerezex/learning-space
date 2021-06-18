#include <iostream>

using namespace std;

int main() {
    // put your code here
    int n;
    cin >> n;
    if (n & (n - 1))
        cout << "NO";
    else
        cout << "YES";
    return 0;
}
