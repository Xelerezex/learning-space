#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int k, conter = 0;
    cin >> k;
    bool buy_tickets = false;
    for (int i = 0; i < n; i++) {
        bool is_not_occupied = true;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0 && is_not_occupied) {
                conter++;
                is_not_occupied = !is_not_occupied;
            } else if (a[i][j] == 0 && !is_not_occupied) {
                conter++;
            } else {
                is_not_occupied = !is_not_occupied;
                conter = 0;
            }
            if (conter == k) {
                buy_tickets = !buy_tickets;
                cout << i + 1;
                break;
            }
        }
        if (buy_tickets) { break; }
        conter = 0;
    }
    if (!buy_tickets) { cout << 0; }
    return 0;
}
