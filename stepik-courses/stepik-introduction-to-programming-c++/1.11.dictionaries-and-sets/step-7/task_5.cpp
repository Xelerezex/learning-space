#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, string> my_dictionary;
    for (int i = 0; i < n; i++) {
        string key, value;
        cin >> key >> value;
        my_dictionary[key] = value;
    }

    string word;
    cin >> word;

    for (auto now : my_dictionary) {
        if (now.second == word) {
            cout << now.first;
        } else if (now.first == word) {
            cout << now.second;
        }
    }
    return 0;
}
