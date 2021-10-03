#include <iostream>
#include <vector>
using std::vector;

int FibLastNum(uint64_t number, uint64_t mod) {
    std::vector<uint64_t> output;
    output.push_back(0);
    output.push_back(1);

    for (uint64_t i = 2; i <= number; ++i) {
        uint64_t item = ((output[i - 1]) + (output[i - 2])) % mod;
        output.push_back(item);
    }

    return output[number];
}


int PisanoPeriodLength(int mod) {
    if (mod == 0) {
        return 0;
    } else if (mod == 1) {
        return 1;
    } else {
        std::vector<uint64_t> fibonacci_array = {0, 1, 1}; // First element of period
        int iteration = 3;                            // All period stsrts with:
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

uint64_t FibSumLastNum(uint64_t number, uint64_t mod)
{
    uint64_t pisano_length = PisanoPeriodLength(mod);
    uint64_t reminder = 0;

    do {
        reminder = number % pisano_length;
        number = reminder;
    } while (reminder >= pisano_length);

    return FibLastNum(number, mod) - 1;
}


int PartialFibSumNum(uint64_t from, uint64_t to)
{
    int sum_of_part = (FibSumLastNum(to + 2, 10) - FibSumLastNum(from + 1, 10));
    return sum_of_part < 0 ? (sum_of_part + 10) : sum_of_part;
}

int main()
{
    uint64_t from, to;
    std::cin >> from >> to;
    std::cout << PartialFibSumNum(from, to) << std::endl;
}
