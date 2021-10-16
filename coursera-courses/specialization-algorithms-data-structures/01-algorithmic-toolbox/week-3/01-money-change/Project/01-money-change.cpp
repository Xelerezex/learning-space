#include "test_runner.h"
#include "profile.h"

unsigned change(unsigned coins) {
    unsigned count = 0;

    while (coins > 0) {
        if (coins >= 10) {
            coins -= 10;
            ++count;
        } else if (coins >= 5) {
            coins -= 5;
            ++count;
        } else {
            coins -= 1;
            ++count;
        }
    }

    return count;
}

int main() {
    {
        LOG_DURATION("Change from 2");
        ASSERT_EQUAL(change(2), 2);
    }
    {
        LOG_DURATION("Change from 28");
        ASSERT_EQUAL(change(28), 6);
    }
    {
        LOG_DURATION("Change from 999");
        ASSERT_EQUAL(change(999), 104);
    }
    {
        LOG_DURATION("Change from 1000");
        ASSERT_EQUAL(change(1000), 100);
    }
}
