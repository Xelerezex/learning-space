#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>


using std::vector;
using std::pair;
using std::cout;
using std::cin;


vector<int> optimal_points(vector<pair<int, int>> &segments) {
    vector<pair<int, pair<int, int>>> ends;
    vector<int> result;

    sort(segments.begin(), segments.end(),
        [](pair<int, int> x, pair<int, int> y) {
            return x.second < y.second;
        }
    );

    for (const auto &end : segments) {
        ends.push_back(make_pair(end.second, end));
    }

    while (ends.size() != 0) {
        int first_end = ends.begin()->first;
        auto it = ends.begin();

        while (it != ends.end()) {
            auto to_del = find_if(ends.begin(), ends.end(),
                [first_end](pair<int, pair<int, int>> x) {
                    return first_end >= x.second.first && first_end <= x.second.second;
            });

            if (to_del != ends.end()) {
                it = ends.erase(to_del);
            } else {
                ++it;
            }

        }
        result.push_back(first_end);
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        cin >> segments[i].first >> segments[i].second;
    }
    vector<int> points = optimal_points(segments);
    cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        cout << points[i] << " ";
    }
}
