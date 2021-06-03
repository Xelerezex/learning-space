#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i - 1] < arr[i]) {
            cout << arr[i] << " ";
        }
    }
    return 0;
}
