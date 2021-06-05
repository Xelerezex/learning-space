#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <locale>
#include <ctype.h>
using namespace std;

void tokenize(string &str, char delim, vector<string> &out) {
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}

int main() {

    int mistakes = 0, n;
    cin >> n >> ws;

    set<string> dictionary;

    set<string> lowercase_dictionary;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word >> ws;
        dictionary.insert(word);

        locale loc;
        string lowercase_word = "";
        for (auto elem : word) {
            lowercase_word += tolower(elem, loc);
        }
        lowercase_dictionary.insert(lowercase_word);
    }

    string petyas_homework;
    getline(cin, petyas_homework);

    if (petyas_homework.empty()) {
        cout << 0;

    } else {

        char space = ' ';
        vector<string> splited_petyas_homework;
        tokenize(petyas_homework, space, splited_petyas_homework);

        for (auto word : splited_petyas_homework) {
            int capital_letters = 0;
            for (int i = 0; i < word.size(); i++) {
                if (isupper(word[i])) {
                    capital_letters++;
                }
            }

            if (capital_letters != 1) {
                mistakes++;


            } else {
                if (dictionary.find(word) == dictionary.end() && capital_letters == 1) {
                    locale locl;
                    string fin_lowercase_word = "";
                    for (auto elem : word) {
                        fin_lowercase_word += tolower(elem, locl);
                    }
                    if (lowercase_dictionary.find(fin_lowercase_word) != lowercase_dictionary.end()) {
                        mistakes++;
                    }
                }
            }
        }
        cout << mistakes;
    }
    return 0;
}
