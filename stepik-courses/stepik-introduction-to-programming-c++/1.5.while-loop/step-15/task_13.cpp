#include <iostream>

using namespace std;

int main() {
    // put your code here
    int first, possible_local_max, second, counter = 0;
    cin >> first >> possible_local_max >> second;
    while (second != 0) {
        if ((first < possible_local_max) && (possible_local_max > second)) {
            counter++;
        }
        first = possible_local_max;
        possible_local_max = second;
        cin >> second;
    }
    cout << counter;
    return 0;
}
