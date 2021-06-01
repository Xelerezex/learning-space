#include <iostream>

using namespace std;

int main() {
    int prev_num = 0, current_num = 0, num, i = 0, min = 0;
    while (cin >> num && num) {
        if (prev_num < current_num && current_num > num) {
            if (min == 0 || min > i) min = i;
            i = 1;
        } else if (i) i++;
        prev_num = current_num, current_num = num;
    }
    cout << min;
    return 0;
}
