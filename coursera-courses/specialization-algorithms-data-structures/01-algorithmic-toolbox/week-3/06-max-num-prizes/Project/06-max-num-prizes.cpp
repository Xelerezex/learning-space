#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
    vector<int> summands;
    //write your code here
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
