#include "test_runner.h"
#include "profile.h"


vector<int> optimal_summands(int n) {
    vector<int> summands;

    int diff = 0,
        number = 1;

    while (diff < n) {
        if (diff + number <= n) {
            summands.push_back(number);
            diff += number;
        } else {
            summands[summands.size() - 1] += n - diff;
            break;
        }
        ++number;
    }
    return summands;
}


int main() {
    {
        int input = 6;
        vector<int> expected = {1, 2, 3};
        LOG_DURATION("Zeroth Test");
        ASSERT_EQUAL(optimal_summands(input), expected);
    }
    {
        int input = 8;
        vector<int> expected = {1, 2, 5};
        LOG_DURATION("Zeroth Test");
        ASSERT_EQUAL(optimal_summands(input), expected);
    }
    {
        int input = 2;
        vector<int> expected = {2};
        LOG_DURATION("Zeroth Test");
        ASSERT_EQUAL(optimal_summands(input), expected);
    }
}
