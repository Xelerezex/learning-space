#include <iostream>
#include <vector>

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
    uint64_t fib_num = 0;
    int mod = 0;

    std::cin  >> fib_num >> mod;
    std::cout << FibModN(fib_num, mod) << std::endl;
}
