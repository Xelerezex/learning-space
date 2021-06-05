#include <iostream>

using namespace std;

int sum_of_stange_nums() {
    int strange_num;
    cin >> strange_num;
    if (strange_num != 0) {
        return strange_num + sum_of_stange_nums();
    }
}

int main() {
    cout << sum_of_stange_nums();
    return 0;
}
