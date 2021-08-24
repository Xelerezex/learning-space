#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define NAME ID

#define LINE __LINE__

#define CONCATINATE(X, Y) X##Y

#define UNIQ(x, y) CONCATINATE(x, y)

#define UNIQ_ID UNIQ(NAME, LINE)


int main() {

  int UNIQ_ID = 10;

  cout << ID19 << endl;

  string UNIQ_ID = "hello";

  vector<string> UNIQ_ID = {"hello", "world"};

  vector<int> UNIQ_ID = {1, 2, 3, 4};
}
