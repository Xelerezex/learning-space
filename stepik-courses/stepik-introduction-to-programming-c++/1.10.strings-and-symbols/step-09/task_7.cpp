#include <iostream>

int main() {
    int first, second, third, fourth;

    std::string s;
    int n = scanf("%d.%d.%d.%d", &first, &second, &third, &fourth);
    std::cin >> s;
    std::cout << (n == 4 && s == "" && first >= 0 && first < 256 && second >= 0 && second < 256 && third >= 0 &&
                  third < 256 && fourth >= 0 && fourth < 256
                  ? "YES" : "NO");
    return 0;
}
