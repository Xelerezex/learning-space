#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, sum_of_positives = 0; //кол-во элементов в массиве
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > 0) {
            sum_of_positives += 1;
        }
    }
    cout << sum_of_positives;
    return 0;
}
