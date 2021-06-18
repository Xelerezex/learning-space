#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    map<string, vector<string>> la_dict;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string lat_word, eng_word;

        cin >> eng_word >> lat_word;

        bool end = false;
        while (!end) {
            cin >> lat_word;

            if (lat_word[lat_word.length() - 1] == ',') {
                lat_word = lat_word.substr(0, lat_word.length() - 1);
            } else {
                end = true;
            }

            la_dict[lat_word].push_back(eng_word);
        }
    }

    cout << la_dict.size() << endl;

    for (auto record : la_dict) {
        cout << record.first << " - ";
        for (size_t i = 0; i < record.second.size(); i++) {
            cout << record.second[i] << ((i + 1 < record.second.size()) ? ", " : "\n");
        }
    }

    return 0;
}
