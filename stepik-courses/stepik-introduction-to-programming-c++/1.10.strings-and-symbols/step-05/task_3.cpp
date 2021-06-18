#include <iostream>

int main() {
    char symbol_case;
    std::cin >> symbol_case;
    std::cout << (symbol_case == char(toupper(symbol_case)) ? char(tolower(symbol_case)) : char(toupper(symbol_case)));
    return 0;
}
