#include "test_runner.h"
#include "profile.h"

long long max_dot_product(vector<int> a, vector<int> b) {
  long long result = 0;

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
        LOG_DURATION("Max value Test: (Create after prog. works)");
        ASSERT_EQUAL(1, -1);
    }
}
