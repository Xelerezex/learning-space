#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

double max_value(vector<pair<double, double>> &items, double MAX_W) {
    sort(items.begin(), items.end(),
        [](pair<double, double> pr1, pair<double, double> pr2){
            return (pr1.first / pr1.second) > (pr2.first / pr2.second);
        }
    );

    double output = 0.0;

    for (size_t it = 0; it < items.size(); ++it) {
        if (items[it].second <= MAX_W) {
            MAX_W -= items[it].second;
            output += items[it].first;
        } else {
            output += (items[it].first / items[it].second) * MAX_W;
            break;
        }
    }

/*    ostringstream convert;
    convert.precision(7);
    convert << output;
    return stod(convert.str());*/
    return output;
}

int main() {
    double vec_size = 0, MAX_W = 0, first, second;
    cin >> vec_size >> MAX_W;

    vector<pair<double, double>> input(vec_size);


    for (size_t it = 0; it < vec_size; ++it) {
        cin >> first >> second;
        input[it] = make_pair(first, second);
    }

    sort(input.begin(), input.end(),
        [](pair<int, int> pr1, pair<int, int> pr2){
            return (pr1.first / pr1.second) > (pr2.first / pr2.second);
        }
    );

    double OUT = max_value(input, MAX_W);
    cout.precision(10);
    cout << OUT << endl;
}
