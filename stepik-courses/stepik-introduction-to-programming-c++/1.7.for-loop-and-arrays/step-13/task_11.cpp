#include <iostream>
#include <vector>

using namespace std;

int main() {
    int elems_in_arr, couples = 0;
    cin >> elems_in_arr;
    vector<int> arr(elems_in_arr);
    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < arr.size(); i++) {
        for (int j = 0; j < i; j++) {
            (arr[j] == arr[i]) ? couples++ : couples;
        }
    }
    cout << couples;
    return 0;
}
