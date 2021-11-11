#include "test_runner.h"
#include "profile.h"
#include "random_generate.h"

int64_t max_dot_product(vector<int64_t> first, vector<int64_t> second) {    // ~ O(3·N·log(N)) -> O(N·log(N))
    if (first.size() != second.size()) {
        return -1;
    }
    int64_t result = 0;

    sort(first.begin(), first.end());           // O(N·log(N))
    sort(second.begin(), second.end());         // O(N·log(N))

    for (size_t it = 0; it < first.size(); ++it) {  // O(N)
        result += (first[it] * second[it]);
    }

    return result;
}

int main() {
    {
        LOG_DURATION("First Test (One pair):");
        vector<int>
        first = {
            23
        },
        second = {
            39
        };
        ASSERT_EQUAL(max_dot_product(first, second), 897);
    }
    {
        LOG_DURATION("Second Test (Three pairs)");
        vector<int>
        first = {
            1, 3, -5
        },
        second = {
            -2, 4, 1,
        };
        ASSERT_EQUAL(max_dot_product(first, second), 23);
    }
    {
        vector<int> first = generate_random_vector(1'000, -100'000, 100'000, 42);
        vector<int> second = generate_random_vector(1'000, -100'000, 100'000, 69);

        LOG_DURATION("Max value Test:");
        ASSERT_EQUAL(max_dot_product(first, second), 178754324962);
    }
}
