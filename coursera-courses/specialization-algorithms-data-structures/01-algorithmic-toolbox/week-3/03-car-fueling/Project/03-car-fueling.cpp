#include "test_runner.h"
#include "profile.h"

int compute_min_refills(uint dist, uint tank, vector<uint> &stops) {
    int qua = 0;
    uint distance = 0, tank_deriv = tank;
    for (auto &stop: stops) {
        distance = stop - distance;
        if (distance > tank) {
            return -1;
        }

        tank_deriv = tank_deriv - distance;

        if (tank_deriv <= distance) {
            tank_deriv = tank;
            ++qua;
        }
    }

    return qua;
}


int main() {
    {
        LOG_DURATION("Stops: 200 375 550 750");
        ASSERT_EQUAL(compute_min_refills(950, 400, {200, 375, 550, 750}), 2);
    }                                            // 200  25
    {                                            // 200  175
        LOG_DURATION("Stops: 1 2 5 9");
        ASSERT_EQUAL(compute_min_refills(10, 3, {1, 2, 5, 9}), -1);
    }
}
