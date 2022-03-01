#include "test_runner.h"

std::vector<int> fast_count_segments(std::vector<std::pair<int, int>> &ranges, std::vector<int> &points)
{
    std::vector<int> result(points.size());

    std::vector<std::pair<int, int>> vec;
    std::unordered_map<int, int> point_to_counts;

    vec.reserve(ranges.size() * 2 + points.size());
    point_to_counts.reserve(points.size());

    for (const auto &pair : ranges)
    {
        vec.push_back({pair.first, 0});
        vec.push_back({pair.second, 2});
    }

    for (const auto &item : points)
    {
        vec.push_back({item, 1});
    }

    std::sort(vec.begin(), vec.end(),
        [](std::pair<int, int>& lhs, std::pair<int, int>& rhs) {
            if (lhs.first == rhs.first)
            {
                return lhs.second < rhs.second;
            }
            else
            {
                return lhs.first < rhs.first;
            }
    });

    int counter = 0;

    for (const auto &pair : vec)
    {
        if (pair.second == 0)
        {
            counter++;
        }
        else if (pair.second == 1)
        {
            point_to_counts.insert({pair.first, counter});
        }
        else /*if (pair.second == 2)*/
        {
            counter--;
        }
    }

    for (size_t i = 0; i < points.size(); i++)
    {
        result[i] = point_to_counts[points[i]];
    }

    return result;
}


int main()
{
    {
        std::vector<std::pair<int, int>> input_segments {
            {0, 5},
            {7, 10}
        };

        std::vector<int> input_points {
            1, 6, 11
        };

        std::vector<int> expected {
            1, 0, 0
        };

        ASSERT_EQUAL(fast_count_segments(input_segments, input_points), expected);
    }
    {
        std::vector<std::pair<int, int>> input_segments {
            {-10, 10},
        };

        std::vector<int> input_points {
            -100, 100, 0
        };

        std::vector<int> expected {
            0, 0, 1
        };

        ASSERT_EQUAL(fast_count_segments(input_segments, input_points), expected);
    }
    {
        std::vector<std::pair<int, int>> input_segments {
            {0, 5},
            {-3, 2},
            {7, 10},
        };

        std::vector<int> input_points {
            1, 6
        };

        std::vector<int> expected {
            2, 0
        };

        ASSERT_EQUAL(fast_count_segments(input_segments, input_points), expected);
    }

    std::cerr << "OK!" << std::endl;
}
