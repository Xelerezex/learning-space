#include <iostream>

using namespace std;

int main() {
    // put your code here
    int h1, m1, s1, h2, m2, s2;
    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
    cout << (h2 - h1) * 3600 + (m2 - m1) * 60 + s2 - s1;
    return 0;
}
