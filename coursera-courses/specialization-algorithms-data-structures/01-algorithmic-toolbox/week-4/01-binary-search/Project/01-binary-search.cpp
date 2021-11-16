#include "test_runner.h"
#include "profile.h"

template <typename RandomIt, typename Value>
RandomIt my_binary_search(RandomIt first, RandomIt last, Value element) {
    RandomIt save_end = last;

    while (first != last) {
        RandomIt middle = first + ((last - first) / 2);
        cerr << *middle << endl;


        if (element == *middle) {
            return middle;
        } else if (element < *middle) {
            last = --middle;
        } else if (element > *middle) {
            first = ++middle;
        }
    }

    return save_end;
}


vector<int> bunch_of_search(const vector<int> data, const vector<int> &to_find) {
    vector<int> temporary;
    for (const auto &element : to_find) {
        if (my_binary_search(data.begin(), data.end(), element) == data.end()) {
            temporary.push_back(-1);
        } else {
            temporary.push_back(*my_binary_search(data.begin(), data.end(), element));
        }
    }
    return temporary;
}


int main() {
    {   vector<int> data = {
            1, 5, 8, 12, 13,
        },
        to_find = {
            8, 1, 23, 1, 10,
        },
        expected = {
            2, 0, -1, 0, -1,
        };
        LOG_DURATION("First banch of tests");
        ASSERT_EQUAL(bunch_of_search(data, to_find), expected);
    }
}
