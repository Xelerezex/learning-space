#include "test_runner.h"
#include "profile.h"

int PisanoPeriodLength(int mod) {
    if (mod == 0) {
        return 0;
    } else if (mod == 1) {
        return 1;
    }

    std::vector<int> fibonacci_array;
    int iteration = 3;
    fibonacci_array.push_back(0);
    fibonacci_array.push_back(1);
    fibonacci_array.push_back(1);

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

int FibLastNum(int number, int mod) {
    std::vector<int> output;
    output.push_back(0);
    output.push_back(1);

    for (int i = 2; i <= number; ++i) {
        int item = ((output[i - 1]) + (output[i - 2])) % mod;
        output.push_back(item);
    }

    return output[number];
}

uint64_t FibModN(uint64_t number_of_fib, int mod) {
    int pisano_size = PisanoPeriodLength(mod);
    uint64_t remainder = number_of_fib % pisano_size,
             output    = FibLastNum(remainder, mod);

    return output;
}

int main() {
    {
        LOG_DURATION("Pisano Period of 0")
        ASSERT_EQUAL(PisanoPeriodLength(0), 0);
    }
    {
        LOG_DURATION("Pisano Period of 1")
        ASSERT_EQUAL(PisanoPeriodLength(1), 1);
    }
    {
        LOG_DURATION("Pisano Period of 2")
        ASSERT_EQUAL(PisanoPeriodLength(2), 3);
    }
    {
        LOG_DURATION("Pisano Period of 3")
        ASSERT_EQUAL(PisanoPeriodLength(3), 8);
    }
    {
        LOG_DURATION("Pisano Period of {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16}")
        std::vector<int> pisano_vect,
                         expected = {1, 3, 8, 6, 20, 24, 16, 12, 24, 60, 10, 24, 28, 48, 40, 24};

        for (int iter = 0; iter < 16; ++iter) {
            pisano_vect.push_back(PisanoPeriodLength(iter + 1));
        }

        ASSERT_EQUAL(pisano_vect, expected);
    }
    {
        LOG_DURATION("Pisano Period of 100")
        ASSERT_EQUAL(PisanoPeriodLength(100), 300);
    }
    {
        LOG_DURATION("Fibonacci Number of 1 & 239")
        ASSERT_EQUAL(FibModN(1U, 239), 1U);
    }
    {
        LOG_DURATION("Fibonacci Number of 115 & 1000")
        ASSERT_EQUAL(FibModN(115U, 1000), 885U);
    }
    {
        LOG_DURATION("Fibonacci Number of 2816213588 & 30524")
        ASSERT_EQUAL(FibModN(2816213588U, 30524), 10249U);
    }
}
