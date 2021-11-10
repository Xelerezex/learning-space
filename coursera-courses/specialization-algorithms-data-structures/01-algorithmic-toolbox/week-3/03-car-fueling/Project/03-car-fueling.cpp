#include "test_runner.h"
#include "profile.h"

int compute_min_refills(int dist, int tank, vector<int> &stops) {
    int qua = 0;
    int index = 0, last_stop = 0;
    stops.push_back(dist);

    while (index < stops.size()) {
        cerr << "qua: " << qua << " index: " << index << " last_stop: " << last_stop << endl;
        if (stops[index] - last_stop <= tank) {
            cerr << "\nOK" << endl;
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
    {
        LOG_DURATION("Stops: 200 375 550 750");
        int dist = 950, tank = 400;
        vector<int> stops = {200, 375, 550, 750};
        ASSERT_EQUAL(compute_min_refills(dist, tank, stops), 2);
    }                                            // 200  25
    {                                            // 200  175
        LOG_DURATION("Stops: 1 2 5 9");
        int dist = 10, tank = 3;
        vector<int> stops = {1, 2, 5, 9};
        ASSERT_EQUAL(compute_min_refills(dist, tank, stops), -1);
    }
}
