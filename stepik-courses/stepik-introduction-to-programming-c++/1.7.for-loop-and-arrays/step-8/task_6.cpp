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
        // Первый положительный элемент
        if ((arr[i] > 0) && (token)) {
            min = arr[i];
            token = !token;
        }
        // Остальные элементы
        if ((arr[i] > 0) && (arr[i] < min)) {
            min = arr[i];
        }
    }
    cout << min;
    return 0;
}
