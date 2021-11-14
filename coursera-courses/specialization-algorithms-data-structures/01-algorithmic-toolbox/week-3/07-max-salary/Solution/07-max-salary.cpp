#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::stringstream;
using std::vector;
using std::string;

bool IsGreaterOrEqual(string &str1, string &str2) {
    return stoi(str1 + str2) > stoi(str2 + str1);
}

string largest_number(vector<string> &strings) {
    sort(strings.begin(), strings.end(),
        [](string str1, string str2){
            return IsGreaterOrEqual(str1, str2);
        }
    );
    stringstream result;
    for (auto iter = strings.begin(); iter != strings.end(); ++iter) {
        result << *iter;
    }

  return result.str();
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
