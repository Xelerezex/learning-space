#include "random_generate.h"
#include "test_runner.h"
#include "profile.h"


template<typename RandomIt>
std::pair<RandomIt, RandomIt> partition(RandomIt start, RandomIt end)
{
    RandomIt pivot     = std::prev(end);
    RandomIt iteration = start;

    for (auto it = start; it != pivot; ++it)
    {
        if (*it < *pivot)
        {
            std::iter_swap(iteration++, it);
        }
    }

    std::iter_swap(iteration, pivot);
    RandomIt iteration_next = next(iteration);

    return {iteration, iteration_next};

}

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
void randomized_quick_sort(RandomIt start, RandomIt end, bool flag)
{
    using distr = std::uniform_int_distribution<typename RandomIt::difference_type>;

    if (std::distance(start, end) > 1)
    {
        std::mt19937 gen;
        distr distribution(0, std::distance(start, end) - 1);
        std::iter_swap(std::next(start, distribution(gen)), prev(end, 1));

        if (flag)
        {
            const auto [first_bound, second_bound] = three_way_partition(start, end);
            randomized_quick_sort(start, first_bound, flag);
            randomized_quick_sort(second_bound, end, flag);
        }
        else
        {
            const auto [first_bound, second_bound] = partition(start, end);
            randomized_quick_sort(start, first_bound, flag);
            randomized_quick_sort(second_bound, end, flag);
        }
    }
}


int main()
{
    {
        std::vector<int> RandomVector = generate_random_vector<int>(1'000'000, -1'000, 1'000, 69);

        {
            LOG_DURATION("Quicksort (random partial, 2 parts) of 1'000'000 elements");
            randomized_quick_sort(RandomVector.begin(), RandomVector.end(), false);
        }

        ASSERT_EQUAL(std::is_sorted(RandomVector.begin(), RandomVector.end()), true);
    }
    {
        std::vector<int> RandomVector = generate_random_vector<int>(1'000'000, -1'000, 1'000, 69);

        {
            LOG_DURATION("Quicksort (random partial, 3 parts) of 1'000'000 elements");
            randomized_quick_sort(RandomVector.begin(), RandomVector.end(), true);
        }

        ASSERT_EQUAL(std::is_sorted(RandomVector.begin(), RandomVector.end()), true);
    }

}
