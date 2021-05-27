#include <iostream>
#include <algorithm>
#include <set>

//-------------------------------------------------------------------------------------------------
std::set<int>::const_iterator FindNearestElement(const std::set<int>& numbers, int border)
{
    auto nearest = numbers.lower_bound(border);

    if (nearest != std::begin(numbers))
    {
        if (nearest == std::end(numbers))
        {
            return std::prev(nearest);
        }
        else
        if (abs(*nearest - border) >= abs(border - *std::prev(nearest)))
        {
            return std::prev(nearest);
        }
        else
        {
            return nearest;
        }
    }
    return nearest;
}
//-------------------------------------------------------------------------------------------------
int main()
{
    std::set<int> numbers = { 1, 4, 6 };
    std::cout <<
        *FindNearestElement(numbers, 0) << " " <<
        *FindNearestElement(numbers, 3) << " " <<
        *FindNearestElement(numbers, 5) << " " <<
        *FindNearestElement(numbers, 6) << " " <<
        *FindNearestElement(numbers, 100) 
    << std::endl;

    std::set<int> empty_set;

    std::cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------