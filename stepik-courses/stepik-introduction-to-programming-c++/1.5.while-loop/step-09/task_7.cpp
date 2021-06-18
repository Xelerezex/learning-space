#include <iostream>

using namespace std;

int main() {
    // put your code here
    int n, max = 0; // Тут я догодался, что можно присваивать при обявлении
    cin >> n;
    max = n;
    while (n != 0) {
        if (max < n) {
            max = n;
        }
        cin >> n;
    }
    cout << max;
    return 0;
}
