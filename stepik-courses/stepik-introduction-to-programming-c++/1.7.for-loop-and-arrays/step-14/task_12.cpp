#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < arr.size(); i++) {
        if (count(arr.begin(), arr.end(), arr[i]) == 1) {
            cout << arr[i] << " ";
        }
    }
    return 0;
}
