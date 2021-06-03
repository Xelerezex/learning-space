#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int couples = 8;
    vector<int> x(couples), y(couples);
    for (int i = 0; i < couples; i++) {
        cin >> x[i] >> y[i];
    }
    bool token = true;
    for (int i = 0; i < couples; i++) {
        for (int j = i + 1; j < couples; j++) {
            if (((x[i] == x[j]) or
                 (y[i] == y[j]) or
                 (abs(x[i] - x[j])
                 ) == abs(y[i] - y[j]))) {
                token = false;
            }
        }
    }
    (token) ? cout << "NO" : cout << "YES";
    return 0;
}
