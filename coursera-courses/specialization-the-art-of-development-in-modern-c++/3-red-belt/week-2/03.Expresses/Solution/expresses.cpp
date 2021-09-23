#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class RouteManager {
public:
    void AddRoute(int start, int finish) {                      // Summary: O(2 * log n) -> O(log n)
        reachable_lists_[start].push_back(finish);              // O(log n)
        reachable_lists_[finish].push_back(start);              // O(log n)
    }


    int FindNearestFinish(int start, int finish) const {        // Summary O(1) + O(log n) + O(N) + O(1) + O(N) -> O(N)
        int result = abs(start - finish);                       // O(1);
        if (reachable_lists_.count(start) < 1) {                // O(log n)   # From cppref
                return result;
        }
        const vector<int>& reachable_stations = reachable_lists_.at(start);    // O(N) <- copy of vector, O(log n) <-search. => O(N) + O(log n) -> O(N)
        if (!reachable_stations.empty()) {      // O(1)
            result = min(   // min <- O(1) =>  O(1) + O(N) + O(1) -> O(N)
                    result,
                    abs(finish - *min_element(      // min_element ~ O(N)     // If make it through lowwer_bound Complexity is O(log n)
                            begin(reachable_stations), end(reachable_stations),
                            [finish](int lhs, int rhs) { return abs(lhs - finish) < abs(rhs - finish); }  // Lambda O(1), cause easy comparation
                    ))
            );
        }
        return result;
    }


private:
    map<int, vector<int>> reachable_lists_;
};


int main() {                             // O(N) * (O(L) + O(N)) <- Complexity of main
    cin.tie(nullptr);                    // O(1)
    ios_base::sync_with_stdio(false);    // ???



    RouteManager routes;

    int query_count;
    cin >> query_count;                 // O(1)

    for (int query_id = 0; query_id < query_count; ++query_id) {      // O(N) * (O(L) + O(N))
                                                                      // Max complexity in cycle -> O(L) + O(N)
        string query_type;                                            // Still linear, but O(L)
        cin >> query_type;
        int start, finish;
        cin >> start >> finish;                                         // O(1) + O(1)
        if (query_type == "ADD") {                                      // String comp O(L), but L max 3 -> O(1) (amortized)
            routes.AddRoute(start, finish);                             // O(log n)
        } else if (query_type == "GO") {
            cout << routes.FindNearestFinish(start, finish) << "\n";    // O(1) + O(N) + O(1)
        }
    }

    return 0;
}
