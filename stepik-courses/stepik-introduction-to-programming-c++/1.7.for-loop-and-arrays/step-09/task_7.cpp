#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, min;
    bool token = true;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < arr.size(); i++) {
        if (((arr[i] % 2 == 1) || (arr[i] % 2 == -1)) && (token)) {
            min = arr[i];
            token = !token;
        }
        if (((arr[i] % 2 == 1) || (arr[i] % 2 == -1)) && (arr[i] < min) && (!token)) {
            min = arr[i];
        }
    }
    if (token) {
        cout << 0;
    } else {
        cout << min;
    }
    return 0;
}
