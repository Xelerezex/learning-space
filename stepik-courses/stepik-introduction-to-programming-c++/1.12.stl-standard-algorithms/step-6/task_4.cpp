#include <iostream>
#include <utility>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct coord {
    int x;
    int y;
    double distance;
};

bool cmp(coord a, coord b) {
    return a.distance < b.distance;
}

int main() {
    int n;
    cin >> n;
    vector<coord> coordinate(n);

    for (int i = 0; i < n; i++) {
        int tmp_x, tmp_y;
        coord temp;
        cin >> tmp_x >> tmp_y;
        temp.x = tmp_x;
        temp.y = tmp_y;
        temp.distance = hypot(abs(tmp_x), abs(tmp_y));
        coordinate[i] = temp;
    }
    sort(coordinate.begin(), coordinate.end(), cmp);
    for (auto now : coordinate) {
        cout << now.x << " " << now.y << endl;
    }
    return 0;
}
