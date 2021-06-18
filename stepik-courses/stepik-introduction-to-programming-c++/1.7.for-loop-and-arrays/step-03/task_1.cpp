#include <iostream>
#include <vector>

int main() {
    // put your code here
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    for (int i = 0; i < arr.size(); i++)
        if (i % 2 == 0) {
            std::cout << arr[i] << " ";
        }
    return 0;
}
