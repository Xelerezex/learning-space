#include "test_runner.h"
#include "profile.h"


vector<int> optimal_points(vector<pair<int, int>> &segments) {
    // map<int, pair<int, int>> ends; <- Doesn't work with map in case {1, 1}, {2, 2}, {3, 3}, {1, 3}
    vector<pair<int, pair<int, int>>> ends;
    //           ^               ^
    // end_o_some_line          pair for that end: {3, {1, 3}}
    vector<int> result;

    // Sort & by max in our vector of pairs:
    sort(segments.begin(), segments.end(),
        [](pair<int, int> x, pair<int, int> y) {
            return x.second < y.second;
        }
    );

    // Generating map
    for (const auto &end : segments) {
        // ends[end.second] = end;
        ends.push_back(make_pair(end.second, end));
    }

    // cerr << ends;

    while (ends.size() != 0) {
        int first_end = ends.begin()->first;
        auto it = ends.begin();

        while (it != ends.end()) {
            auto to_del = find_if(ends.begin(), ends.end(),
                [first_end](pair<int, pair<int, int>> x) {
                    return first_end >= x.second.first && first_end <= x.second.second;
            });
            // cerr << first_end << " : " << *to_del <<endl;

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
    {
        vector<pair<int, int>> test = {
            {1, 1},
            {2, 2},
            {3, 3},
            {1, 3},
        };
        vector<int> expected = {
            1, 2, 3
        };
        LOG_DURATION("Zeroth Test");
        ASSERT_EQUAL(optimal_points(test), expected);
    }
    {
        vector<pair<int, int>> test = {
            {1, 3},
            {2, 5},
            {3, 6},
        };
        vector<int> expected = {
            3
        };
        LOG_DURATION("First Test");
        ASSERT_EQUAL(optimal_points(test), expected);
    }
    {
        vector<pair<int, int>> test = {
            {4, 7},
            {1, 3},
            {2, 5},
            {5, 6},
        };
        vector<int> expected = {
            3, 6
        };
        LOG_DURATION("Second Test");
        ASSERT_EQUAL(optimal_points(test), expected);
    }
    {
        vector<pair<int, int>> test = {
            {5, 10},
            {5, 9},
            {6, 7},
            {8, 9},
        };
        vector<int> expected = {
            7, 9
        };
        LOG_DURATION("Third Test");
        ASSERT_EQUAL(optimal_points(test), expected);
    }
    {
        vector<pair<int, int>> test = {
            {6, 8},
            {1, 3},
            {3, 5},
            {8, 10},
        };
        vector<int> expected = {
            3, 8
        };
        LOG_DURATION("Fourth Test");
        ASSERT_EQUAL(optimal_points(test), expected);
    }
    {
        vector<pair<int, int>> test = {
            {1, 3},
            {2, 3},
            {5, 8},
            {7, 8},
        };
        vector<int> expected = {
            3, 8
        };
        LOG_DURATION("Fifth Test");
        ASSERT_EQUAL(optimal_points(test), expected);
    }
    {
        vector<pair<int, int>> test = {
            {1, 3},
            {1, 2},
        };
        vector<int> expected = {
            2
        };
        LOG_DURATION("Sixth Test");
        ASSERT_EQUAL(optimal_points(test), expected);
    }
    {
        vector<pair<int, int>> test = {
            {1, 3},
            {1, 3},
        };
        vector<int> expected = {
            3
        };
        LOG_DURATION("Seventh Test");
        ASSERT_EQUAL(optimal_points(test), expected);
    }
    {
        vector<pair<int, int>> test = {
            {1, 2},
            {5, 8},
        };
        vector<int> expected = {
            2, 8
        };
        LOG_DURATION("Eighth Test");
        ASSERT_EQUAL(optimal_points(test), expected);
    }
    {
        vector<pair<int, int>> test = {
            {1, 3},
            {5, 8},
            {9, 10},
            {9, 11},
        };
        vector<int> expected = {
            3, 8, 10
        };
        LOG_DURATION("Nineth Test");
        ASSERT_EQUAL(optimal_points(test), expected);
    }
    {
        vector<pair<int, int>> test = {
            {1, 3},
            {5, 7},
            {2, 5},
        };
        vector<int> expected = {
            3, 7
        };
        LOG_DURATION("Tenth Test");
        ASSERT_EQUAL(optimal_points(test), expected);
    }
    {
        vector<pair<int, int>> test = {
            {41, 42},
            {52, 52},
            {63, 63},
            {80, 82},
            {78, 79},
            {35, 35},
            {22, 23},
            {31, 32},
            {44, 45},
            {81, 82},
            {36, 38},
            {10, 12},
            {1, 1},
            {23, 23},
            {32, 33},
            {87, 88},
            {55, 56},
            {69, 71},
            {89, 91},
            {93, 93},
            {38, 40},
            {33, 34},
            {14, 16},
            {57, 59},
            {70, 72},
            {36, 36},
            {29, 29},
            {73, 74},
            {66, 68},
            {36, 38},
            {1, 3},
            {49, 50},
            {68, 70},
            {26, 28},
            {30, 30},
            {1, 2},
            {64, 65},
            {57, 58},
            {58, 58},
            {51, 53},
            {41, 41},
            {17, 18},
            {45, 46},
            {4, 4},
            {0, 1},
            {65, 67},
            {92, 93},
            {84, 85},
            {75, 77},
            {39, 41},
            {15, 15},
            {29, 31},
            {83, 84},
            {12, 14},
            {91, 93},
            {83, 84},
            {81, 81},
            {3, 4},
            {66, 67},
            {8, 8},
            {17, 19},
            {86, 87},
            {44, 44},
            {34, 34},
            {74, 74},
            {94, 95},
            {79, 81},
            {29, 29},
            {60, 61},
            {58, 59},
            {62, 62},
            {54, 56},
            {58, 58},
            {79, 79},
            {89, 91},
            {40, 42},
            {2, 4},
            {12, 14},
            {5, 5},
            {28, 28},
            {35, 36},
            {7, 8},
            {82, 84},
            {49, 51},
            {2, 4},
            {57, 59},
            {25, 27},
            {52, 53},
            {48, 49},
            {9, 9},
            {10, 10},
            {78, 78},
            {26, 26},
            {83, 84},
            {22, 24},
            {86, 87},
            {52, 54},
            {49, 51},
            {63, 64},
            {54, 54},
        };
        vector<int> expected = {
            1, 4, 5, 8, 9, 10, 14, 15, 18, 23, 26, 28, 29, 30, 32, 34, 35, 36,
            40, 41, 44, 46, 49, 52, 54, 56, 58, 61, 62, 63, 65, 67, 70, 74, 77, 78,
            79, 81, 84, 87, 91, 93, 95,
        };
        LOG_DURATION("Eleventh Test");
        ASSERT_EQUAL(optimal_points(test), expected);
    }
}
