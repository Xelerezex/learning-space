#include <iostream>

using namespace std;

int main() {
    string word;
    string longest_word = "";
    while (cin >> word) {
        if (word.length() > longest_word.length()) {
            longest_word = word;
        }
    }
    cout << longest_word;
    return 0;
}
