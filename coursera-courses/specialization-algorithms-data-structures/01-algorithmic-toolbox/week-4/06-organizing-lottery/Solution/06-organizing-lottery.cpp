#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>

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
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int ranges_size, points_size;
    std::cin >> ranges_size >> points_size;
    std::vector<std::pair<int, int>> ranges;
    ranges.reserve(ranges_size);

    int start, end;
    for (size_t it = 0; it < ranges_size; ++it)
    {
        std::cin >> start >> end;
        if (start <= end)
        {
            ranges.push_back({start, end});
        }
    }

    std::vector<int> points(points_size);
    for (size_t it = 0; it < points_size; ++it)
    {
        std::cin >> points[it];
    }

    std::vector<int> result = fast_count_segments(ranges, points);

    for (size_t it = 0; it < result.size(); ++it)
    {
        std::cout << result[it] << " ";
    }
}
