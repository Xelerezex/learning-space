#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; //кол-во элементов в массиве, в векторе
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 0) {
            cout << arr[i] << " ";
        }
    }
    return 0;
}
