#include "test_runner.h"
#include "profile.h"

int PisanoPeriodLength(int mod) {
    if (mod == 0) {
        return 0;
    } else if (mod == 1) {
        return 1;
    }

    std::vector<uint64_t> fibonacci_array;
    uint64_t iteration = 3;
    fibonacci_array.push_back(0);
    fibonacci_array.push_back(1);
    fibonacci_array.push_back(1);

    while(true) {
        uint64_t fibwithmod = (fibonacci_array[iteration - 1] + fibonacci_array[iteration - 2]) % mod;
        fibonacci_array.push_back(fibwithmod);

        if ((fibonacci_array[iteration - 2] == 0) && (fibonacci_array[iteration - 1] == 1)) {
            break;
        }
        ++iteration;
    }

    return (fibonacci_array.size() - 3);
}

uint64_t FibSumNum(uint64_t fib_num) {
    if (fib_num == 0) {
        return 0;
    } else if (fib_num == 1) {
        return 1;
    } else {
        uint64_t pisanoper = PisanoPeriodLength(10),
                 reminder  = fib_num % pisanoper,
                 first     = 0,
                 second    = 1;

        if (pisanoper == 0) {
            return 0;
        }

        for(uint64_t iter = 0; iter <= reminder; iter++)
        {
           uint64_t fib = (first + second) % pisanoper;
           first = second;
           second = fib;
        }

        return (second - 1) % 10;
    }


}

int main() {
    {
        LOG_DURATION("Fibonacci sum of 3");
        ASSERT_EQUAL(FibSumNum(3), 4U);
    }
    {
        LOG_DURATION("Fibonacci sum of 100");
        ASSERT_EQUAL(FibSumNum(100), 5U);
    }
    {
        LOG_DURATION("Fibonacci sum of 100'000");
        ASSERT_EQUAL(FibSumNum(100'000), 5U);
    }
    {
        LOG_DURATION("Fibonacci sum of 1'000'000'000'000'000'000");
        ASSERT_EQUAL(FibSumNum(1'000'000'000'000'000'000), 5U);
    }
        {
        LOG_DURATION("Fibonacci sum of 2'999'999'999'999'999'999");
        ASSERT_EQUAL(FibSumNum(2'999'999'999'999'999'999), 0U);
    }
}
