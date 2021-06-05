#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> strange_sequence;
    for (int i = 0; i < n; i++) {
        int x;
        bool is_added;
        cin >> x;
        is_added = strange_sequence.insert(x).second;
        cout << (is_added ? "NO" : "YES") << "\n";
    }
    return 0;
}
