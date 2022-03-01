#include "test_runner.h"

long long get_number_of_inversions(std::vector<int> &data, std::vector<int> &temporary, size_t start, size_t end) {
    long long number_of_inversions = 0;

    if (end <= start + 1)
    {
        return number_of_inversions;
    }

    size_t middle = start + (end - start) / 2;

    number_of_inversions += get_number_of_inversions(data, temporary, start, middle);
    number_of_inversions += get_number_of_inversions(data, temporary, middle, end);

    size_t data_it = start, data_mid_it = middle, temp_it = start;

    while (data_it < middle && data_mid_it < end)
    {
        if (data[data_it] > data[data_mid_it])
        {
            number_of_inversions += end - data_mid_it;
            temporary[temp_it++] = data[data_it++];
        }
        else
        {
            temporary[temp_it++] = data[data_mid_it++];
        }
    }

    while (data_it < middle)
    {
        temporary[temp_it++] = data[data_it++];
    }

    while (data_mid_it < end)
    {
        temporary[temp_it++] = data[data_mid_it++];
    }

    std::copy(temporary.begin() + start, temporary.begin() + end, data.begin() + start);
    return number_of_inversions;
}


int main()
{
    {
        std::vector<int> data = {2, 3, 9, 2, 9};
        std::vector<int> temporary(data.size());
        ASSERT_EQUAL(get_number_of_inversions(data, temporary, 0, (data.size())), 2);
    }
    {
        std::vector<int> data = {9, 8, 7, 3, 2, 1,};
        std::vector<int> temporary(data.size());
        ASSERT_EQUAL(get_number_of_inversions(data, temporary, 0, (data.size())), 15);
    }
    std::cerr << "OK!" << std::endl;
}
