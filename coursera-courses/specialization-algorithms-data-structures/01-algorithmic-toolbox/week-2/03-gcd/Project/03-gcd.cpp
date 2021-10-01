#include "test_runner.h"
#include "profile.h"

uint64_t EuclidGCD(uint64_t first, uint64_t second) {
    return (second == 0) ? first : EuclidGCD(second, first % second);
}

int main() {
    {
        LOG_DURATION("Greatest common divisor of 1 & 1");
        ASSERT_EQUAL(EuclidGCD(1, 1), 1U);
    }
    {
        LOG_DURATION("Greatest common divisor of 1 & 2");
        ASSERT_EQUAL(EuclidGCD(1, 2), 1U);
    }
    {
        LOG_DURATION("Greatest common divisor of 2 & 1");
        ASSERT_EQUAL(EuclidGCD(2, 1), 1U);
    }
    {
        LOG_DURATION("Greatest common divisor of 10 & 6");
        ASSERT_EQUAL(EuclidGCD(10, 6), 2U);
    }
    {
        LOG_DURATION("Greatest common divisor of 28851538 & 1183019");
        ASSERT_EQUAL(EuclidGCD(28851538, 1183019), 17657U);
    }
    {
        LOG_DURATION("Greatest common divisor of 20000000000 & 2000000000");
        ASSERT_EQUAL(EuclidGCD(2000000000, 2000000000), 2000000000U);
    }
}
