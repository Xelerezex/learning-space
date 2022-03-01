#include <iostream>
#include <vector>


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
    int vector_size;
    std::cin >> vector_size;

    std::vector<int> data(vector_size);
    std::vector<int> temporary(data.size());

    for (size_t it = 0; it < data.size(); ++it)
    {
        std::cin >> data[it];
    }

    std::cout << get_number_of_inversions(data, temporary, 0, data.size()) << std::endl;
}
