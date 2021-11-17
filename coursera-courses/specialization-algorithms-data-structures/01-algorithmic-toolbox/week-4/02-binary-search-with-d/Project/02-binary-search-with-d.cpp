#include "test_runner.h"
#include "profile.h"
#include "random_generate.h"

template <typename RandomIt, typename Value>
RandomIt my_binary_search(RandomIt first, RandomIt last, Value element) {
    RandomIt save_end = last;

    while (first != last) {
        RandomIt middle = first + ((last - first) / 2);
        //cerr << *middle << endl;
        if (element < *middle) {
            last = middle;
        } else if (element > *middle) {
            first = ++middle;
        } else {
            if (*prev(middle) == element) {
                return my_binary_search(first, --middle, element);
            } else {
                return middle;
            }
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
            temporary.push_back(distance(data.begin(),
                                         my_binary_search(data.begin(), data.end(), element))
                                );
        }
    }
    return temporary;
}

int main() {
    {   vector<int> data = { //           9
            1, 5, 5, 5, 5, 8, 12, 13, 13, 13, 13, 13,
        },
        to_find = {
            8, 1, 23, 1, 10, 13
        },
        expected = {
            5, 0, -1, 0, -1, 7
        };
        LOG_DURATION("First banch of tests");
        ASSERT_EQUAL(bunch_of_search(data, to_find), expected);
    }
    {
        vector<int> data = {
            1, 2, 3, 4, 5, 5, 5, 5, 5, 5, 5, 6
        },
        to_find = {
            1, 2, 3, 4, 5, 6
        },
        expected = {
            0, 1, 2, 3, 4, 11
        };
        LOG_DURATION("Second banch of tests");
        ASSERT_EQUAL(bunch_of_search(data, to_find), expected);
    }
}
