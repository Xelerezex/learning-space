#include <iostream>

using namespace std;

int main() {
    // put your code here
    int n, summ;
    summ = 0;
    cin >> n;
    while (n != 0) {
        summ += n;
        cin >> n;
    }
    cout << summ;
    return 0;
}
