#include <iostream>
#include <string>

using namespace std;

int main() {
    int spaces = 0;
    string s;
    getline(cin, s);
    for (auto c : s) {
        if (isspace(c)) {
            spaces += 1;
        }
    }
    cout << spaces + 1;
    return 0;
}
