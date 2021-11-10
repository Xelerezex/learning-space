#include <iostream>
#include <vector>

using std::endl;
using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> &stops) {
    int qua = 0;
    int index = 0, last_stop = 0;
    stops.push_back(dist);

    while (index < stops.size()) {
        if (stops[index] - last_stop <= tank) {
            ++index;
            continue;
        } else if ((stops[index] - stops[index - 1] > tank) || (index == 0)) {
            return -1;
        } else {
            last_stop = stops[index - 1];
            qua += 1;
        }
    }
    return qua;
}



int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
