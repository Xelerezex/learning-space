#include "test_runner.h"
#include "profile.h"

// F(n) * (F(n-1) + F(n))

int PisanoPeriodLength(int mod) {
    if (mod == 0) {
        return 0;
    } else if (mod == 1) {
        return 1;
    } else {
        std::vector<uint64_t> fibonacci_array = {0, 1, 1}; // First element of period
        int iteration = 3;                                 // All period starts with:
                                                           // 0, 1, 1
        while(true) {
            int fibwithmod = (fibonacci_array[iteration - 1] + fibonacci_array[iteration - 2]) % mod;
            fibonacci_array.push_back(fibwithmod);

            if ((fibonacci_array[iteration - 2] == 0) && (fibonacci_array[iteration - 1] == 1)) {
                break;
            }
            ++iteration;
        }
        return (fibonacci_array.size() - 3);
    }
}

int FibLastNum(int number, int mod) {
    std::vector<int> fib_array = {0, 1};  // First value of fib array

    for (int iter = 2; iter <= number; ++iter) {
        int last = ((fib_array[iter - 1]) + (fib_array[iter - 2])) % mod;
        fib_array.push_back(last);
    }

    return fib_array[number];
}

uint64_t FibModN(uint64_t number_of_fib, int mod = 10) {
    int pisano_size = PisanoPeriodLength(mod);
    uint64_t remainder = number_of_fib % pisano_size,
             output    = FibLastNum(remainder, mod);

    return output;
}

int FibLastNumSumSquares(uint64_t number) {
    return FibModN(number) * (FibModN(number) + FibModN(number - 1)) % 10;
}

int main() {
    {
        LOG_DURATION("Summ of Squares of 7");
        ASSERT_EQUAL(FibLastNumSumSquares(7), 3);
    }
    {
        LOG_DURATION("Summ of Squares of 73");
        ASSERT_EQUAL(FibLastNumSumSquares(73), 1);
    }
    {
        LOG_DURATION("Summ of Squares of 1234567890");
        ASSERT_EQUAL(FibLastNumSumSquares(1234567890), 0);
    }
    {
        LOG_DURATION("Summ of Squares of 1'000'000'000'000'000'000");
        ASSERT_EQUAL(FibLastNumSumSquares(1'000'000'000'000'000'000), 5);
    }
}
