#include "test_runner.h"
#include "profile.h"


uint64_t EuclidGCD(uint64_t first, uint64_t second) {
    return (second == 0) ? first : EuclidGCD(second, first % second);
}

uint64_t LCM(uint64_t first, uint64_t second) {
    uint64_t gcd       = EuclidGCD(first, second),
             f_div_gcd = first  / gcd,
             s_div_gcd = second / gcd;

    return gcd * f_div_gcd * s_div_gcd;
}

int main() {
    {
        LOG_DURATION("Least Common Multiple of 1 & 1");
        ASSERT_EQUAL(LCM(1, 1), 1U);
    }
    {
        LOG_DURATION("Least Common Multiple of 3 & 2");
        ASSERT_EQUAL(LCM(3, 2), 6U);
    }
    {
        LOG_DURATION("Least Common Multiple of 3 & 5");
        ASSERT_EQUAL(LCM(3, 5), 15U);
    }
    {
        LOG_DURATION("Least Common Multiple of 2 & 5");
        ASSERT_EQUAL(LCM(2, 5), 10U);
    }
    {
        LOG_DURATION("Least Common Multiple of 6 & 8");
        ASSERT_EQUAL(LCM(6, 8), 24U);
    }
    {
        LOG_DURATION("Least Common Multiple of 28851538 & 1183019");
        ASSERT_EQUAL(LCM(28851538U, 1183019U), 1933053046U);
    }
    {
        LOG_DURATION("Least Common Multiple of 2000000000 & 1999999999U");
        ASSERT_EQUAL(LCM(2000000000U, 1999999999U), 3999999998000000000U);
    }
    {
        LOG_DURATION("Least Common Multiple of 2000000000 & 2000000000");
        ASSERT_EQUAL(LCM(2000000000U, 2000000000U), 2000000000U);
    }
}
