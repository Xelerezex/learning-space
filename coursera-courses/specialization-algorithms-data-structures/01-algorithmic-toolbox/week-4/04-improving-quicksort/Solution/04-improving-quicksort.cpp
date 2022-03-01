#include <algorithm>
#include <iostream>
#include <vector>
#include <random>

template<class RandomIt>
std::pair<RandomIt, RandomIt> three_way_partition(RandomIt start, RandomIt end) {
    end = prev(end);                       // Last pointing not to end(), but on last element
    const auto& pivot = *end;              // Pivot value

    RandomIt iter_first  = start;
    RandomIt iter_second = start;
    RandomIt iter_end    = end;

    while (iter_second != iter_end)
    {
        if (*iter_second < pivot)
        {
            std::iter_swap(iter_first, iter_second);
            iter_first  = next(iter_first);
            iter_second = next(iter_second);
        }
        else if (*iter_second > pivot)
        {
            iter_end = prev(iter_end);
            std::iter_swap(iter_second, iter_end);
        }
        else
        {
            iter_second = next(iter_second);
        }
    }

    std::iter_swap(iter_second, end);

    iter_second = next(iter_second);
    return {iter_first, iter_second};
}

template<typename RandomIt>
void randomized_quick_sort(RandomIt start, RandomIt end)
{
    using distr = std::uniform_int_distribution<typename RandomIt::difference_type>;

    if (std::distance(start, end) > 1)
    {
        std::mt19937 gen;
        distr distribution(0, std::distance(start, end) - 1);
        std::iter_swap(std::next(start, distribution(gen)), prev(end, 1));

        const auto [first_bound, second_bound] = three_way_partition(start, end);
        randomized_quick_sort(start, first_bound);
        randomized_quick_sort(second_bound, end);
    }
}

int main()
{
    size_t vector_size;
    std::cin >> vector_size;

    std::vector<size_t> data(vector_size);

    for (size_t it = 0; it < data.size(); ++it)
    {
        std::cin >> data[it];
    }

    randomized_quick_sort(data.begin(), data.end());

    for (size_t it = 0; it < data.size(); ++it)
    {
        std::cout << data[it] << ' ';
    }
}
