#include "test_runner.h"
#include "profile.h"

int FibLastNum(int number) {
    std::vector<int> output;
    output.push_back(0);
    output.push_back(1);

    for (int i = 2; i <= number; ++i) {
        int item = ((output[i - 1]) + (output[i - 2])) % 10;
        output.push_back(item);
    }

    return output[number];
}

int main() {
    {
        LOG_DURATION("Fibonacci last number of 0");
        ASSERT_EQUAL(FibLastNum(0), 0);
    }
    {
        LOG_DURATION("Fibonacci last number of 1");
        ASSERT_EQUAL(FibLastNum(1), 1);
    }
    {
        LOG_DURATION("Fibonacci last number of 3");
        ASSERT_EQUAL(FibLastNum(3), 2);
    }
    {
        LOG_DURATION("Fibonacci last number of 100");
        ASSERT_EQUAL(FibLastNum(100), 5);
    }
    {
        LOG_DURATION("Fibonacci last number of 139");
        ASSERT_EQUAL(FibLastNum(139), 1);
    }
    {
        LOG_DURATION("Fibonacci last number of 170");
        ASSERT_EQUAL(FibLastNum(170), 5);
    }
    {
        LOG_DURATION("Fibonacci last number of 91239");
        ASSERT_EQUAL(FibLastNum(91239), 6);
    }
    {
        LOG_DURATION("Fibonacci last number of 100000");
        ASSERT_EQUAL(FibLastNum(100000), 5);
    }
}
