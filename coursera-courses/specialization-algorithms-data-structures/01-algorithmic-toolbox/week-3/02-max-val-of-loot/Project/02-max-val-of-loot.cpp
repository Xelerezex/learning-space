#include "test_runner.h"
#include "profile.h"

double max_value(vector<pair<double, double>> &items, double MAX_W) {
    sort(items.begin(), items.end(),
        [](pair<double, double> pr1, pair<double, double> pr2){
            return (pr1.first / pr1.second) > (pr2.first / pr2.second);
        }
    );

    double output = 0.0000;

    for (size_t it = 0; it < items.size(); ++it) {
        if (items[it].second <= MAX_W) {
            MAX_W -= items[it].second;
            output += items[it].first;
        } else {
            output += (items[it].first / items[it].second) * MAX_W;
            break;
        }
    }

    ostringstream convert;
    convert.precision(7); // 10
    convert << output;
    return stod(convert.str());
}

int main() {
    {
        LOG_DURATION("First test");
        double /*QUANTITY = 3,*/ MAX_W = 50;
        // Get sorted by first / second
        vector<pair<double, double>> input = {
            {120, 30},  // 4
            {60, 20},   // 3
            {100, 50},  // 2
        };
        ASSERT_EQUAL(max_value(input, MAX_W), 180.0000);
    }
    {
        LOG_DURATION("Second test");
        double /*QUANTITY = 1,*/ MAX_W = 10;
        // Get sorted by first / second
        vector<pair<double, double>> input = {
            {500, 30},
        };
        ASSERT_EQUAL(max_value(input, MAX_W), 166.6667);
    }
}
