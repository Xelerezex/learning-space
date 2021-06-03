#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    bool token = true;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < arr.size(); i++) {
        if (token) {
            if (
                    (
                            (arr[i - 1] > 0) && (arr[i] > 0)
                    ) || (
                            (arr[i - 1] < 0) && (arr[i] < 0)
                    )) {
                if (arr[i - 1] < arr[i]) {
                    cout << arr[i - 1] << " " << arr[i] << " ";
                } else {
                    cout << arr[i] << " " << arr[i - 1] << " ";
                }
                token = !token;
            }
        }
    }
    return 0;
}
