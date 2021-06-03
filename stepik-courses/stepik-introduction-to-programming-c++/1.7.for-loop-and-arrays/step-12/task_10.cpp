#include <iostream>
#include <vector>

using namespace std;

int main() {
    int elements_in_arr, last_elem_holder;
    cin >> elements_in_arr;
    vector<int> arr(elements_in_arr);
    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }
    last_elem_holder = arr[arr.size() - 1];
    for (int i = arr.size() - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = last_elem_holder;
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
