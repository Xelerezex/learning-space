#include <iostream>

using namespace std;

int main() {
    // put your code here
    int first_num, second_num;
    cin >> first_num >> second_num;
    if (first_num >= second_num) {
        cout << first_num;
    } else {
        cout << second_num;
    }
    return 0;
}
