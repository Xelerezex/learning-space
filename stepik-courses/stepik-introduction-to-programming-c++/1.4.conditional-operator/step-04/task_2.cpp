#include <iostream>

using namespace std;

int main() {
    // put your code here
    int first_num, second_num;
    cin >> first_num >> second_num;
    if (first_num > second_num) {
        cout << 1;
    } else if (first_num < second_num) {
        cout << 2;
    } else {
        cout << 0;
    }
    return 0;
}
