#include "test_runner.h"
#include "profile.h"


struct Segment {
    int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
    vector<int> points;
    //write your code here
    for (size_t i = 0; i < segments.size(); ++i) {
        points.push_back(segments[i].start);
        points.push_back(segments[i].end);
    }
    return points;
}

int main() {
    {
        vector<Segment> test = {
            {1, 3},
            {2, 5},
            {3, 6},
        };
        vector<int> expected = {
            3
        };
        LOG_DURATION("First Test:");
        ASSERT_EQUAL(optimal_points(test), expected);
    }
    {
        vector<Segment> test = {
            {1, 3},
            {2, 5}
            {4, 7},
            {5, 6},
        };
        vector<int> expected = {
            3, 6
        };
        LOG_DURATION("Second Test:");
        ASSERT_EQUAL(optimal_points(test), expected);
    }
}
