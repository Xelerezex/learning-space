#include "test_runner.h"
#include "profile.h"

int Fibonacci(int number) {
    std::vector<int> output;
    output.push_back(0);
    output.push_back(1);

    for (int i = 2; i <= number; ++i) {
        int item = (output[i - 1]) + (output[i - 2]);
        output.push_back(item);
    }

    return output[number];
}

int main() {
    {
        LOG_DURATION("Fibonacci number from 0 ");
        ASSERT_EQUAL(Fibonacci(0), 0);
    }
    {
        LOG_DURATION("Fibonacci number from 1 ");
        ASSERT_EQUAL(Fibonacci(1), 1);
    }
    {
        LOG_DURATION("Fibonacci number from 3 ");
        ASSERT_EQUAL(Fibonacci(3), 2);
    }
    {
        LOG_DURATION("Fibonacci number from 10");
        ASSERT_EQUAL(Fibonacci(10), 55);
    }
    {
        LOG_DURATION("Fibonacci number from 45");
        ASSERT_EQUAL(Fibonacci(45), 1134903170);
    }
}
