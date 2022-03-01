#include "test_runner.h"


double distance(
    const std::pair<int64_t, int64_t>& lhs,
    const std::pair<int64_t, int64_t>& rhs
)
{
    return sqrt(
               (rhs.first  - lhs.first)  * (rhs.first  - lhs.first)
             + (rhs.second - lhs.second) * (rhs.second - lhs.second)
           );
}


bool less_than_on_x(std::pair<int64_t, int64_t>& lhs, std::pair<int64_t, int64_t>& rhs)
{
    return (lhs.first == rhs.first) ? (lhs.second < rhs.second) : (lhs.first < rhs.first);
}


bool less_than_on_y(std::pair<int64_t, int64_t>& lhs, std::pair<int64_t, int64_t>& rhs)
{
    return (lhs.second == rhs.second) ? (lhs.first < rhs.first) : (lhs.second < rhs.second);
}


void merge(std::vector<std::pair<int64_t, int64_t>>& points, int64_t start, int64_t end) {
    if (start >= end)
    {
        return;
    }

    int64_t middle = start + (end - start) / 2;
    int64_t s_iter = start;
    int64_t m_iter = middle + 1;
    std::vector<std::pair<int64_t, int64_t>> data;
    data.reserve(end - start + 1);

    while (s_iter <= middle and m_iter <= end)
    {
        if (less_than_on_y(points[s_iter], points[m_iter]))
        {
            data.emplace_back(points[s_iter].first, points[s_iter].second);
            s_iter++;
        }
        else
        {
            data.emplace_back(points[m_iter].first, points[m_iter].second);
            m_iter++;
        }
    }

    while (s_iter <= middle)
    {
        data.emplace_back(points[s_iter].first, points[s_iter].second);
        s_iter++;
    }

    while (m_iter <= end)
    {
        data.emplace_back(points[m_iter].first, points[m_iter].second);
        m_iter++;
    }

    for (size_t it = 0; it < data.size(); ++it)
    {
        points[start + it] = data.at(it);
    }
}

double minimal_distance(std::vector<std::pair<int64_t, int64_t>>& points, int64_t start, int64_t end)
{
    if (start >= end)
    {
        return std::numeric_limits<double>::max();
    };

    if (end - start == 1)
    {
        if (not less_than_on_y(points[start], points[end]))
        {
            std::swap(points[start], points[end]);
        }

        return distance(points[start], points[end]);
    }

    int64_t middle = start + (end - start) / 2;
    std::pair<int64_t, int64_t> middle_point = points.at(middle);

    double minimal = std::min(minimal_distance(points, start, middle), minimal_distance(points, middle + 1, end));

    std::vector<std::pair<int64_t, int64_t>> strip_points;

    merge(points, start, end);
    for (int64_t i = start; i <= end; i++)
    {
        if (std::abs(points[i].first - middle_point.first) <= minimal)
        {
            strip_points.emplace_back(points[i].first, points[i].second);
        }
    }

    for (size_t i = 0; i < strip_points.size() - 1; i++)
    {
        for (size_t j = i + 1; j < strip_points.size() and j - i < 8; j++)
        {
            minimal = std::min(minimal, distance(strip_points[i], strip_points[j]));
        }
    }
    return minimal;
}

int main() {
    {
        std::vector<std::pair<int64_t, int64_t>> points {
            {0, 0},
            {3, 4},
        };

        std::sort(points.begin(), points.end(), &less_than_on_x);

        std::ostringstream os;
        os << std::fixed << std::setprecision(9) << minimal_distance(points, 0, (points.size() - 1));

        ASSERT_EQUAL(os.str(), "5.000000000");
    }
    {
        std::vector<std::pair<int64_t, int64_t>> points {
            {7, 7},
            {1, 100},
            {4, 8},
            {7, 7}
        };

        std::sort(points.begin(), points.end(), &less_than_on_x);

        std::ostringstream os;
        os << std::fixed << std::setprecision(9) << minimal_distance(points, 0, (points.size() - 1));

        ASSERT_EQUAL(os.str(), "0.000000000");
    }
    {
        std::vector<std::pair<int64_t, int64_t>> points {
            {4, 4},
            {-2, -2},
            {-3, -4},
            {-1, 3},
            {2, 3},
            {-4, 0},
            {1, 1},
            {-1, -1},
            {3, -1},
            {-4, 2},
            {-2, 4},
        };

        std::sort(points.begin(), points.end(), &less_than_on_x);

        std::ostringstream os;
        os << std::fixed << std::setprecision(9) << minimal_distance(points, 0, (points.size() - 1));

        ASSERT_EQUAL(os.str(), "1.414213562");
    }

    std::cerr << "OK!" << std::endl;
}
