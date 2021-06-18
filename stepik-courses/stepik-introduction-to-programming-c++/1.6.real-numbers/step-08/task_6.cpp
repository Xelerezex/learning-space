#include <iostream>
#include <iomanip> //Для точности в 11 знаков после запятой.

using namespace std;

int main() {
    // put your code here
    int n, counter = 0, sum = 0;
    cin >> n;
    while (n != 0) {
        sum += n;
        counter++;
        cin >> n;
    }
    cout.precision(11);
    cout << double(sum) / double(counter);
    return 0;
}
