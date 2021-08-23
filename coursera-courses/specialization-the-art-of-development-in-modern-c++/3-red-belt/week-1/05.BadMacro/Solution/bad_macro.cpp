#include "test_runner.h"

#include <ostream>
using namespace std;

#define PRINT_VALUES(out, x, y) out << (x) << '\n' << (y) << '\n'


int main() {
    TestRunner tr;
    tr.RunTest([] {
        ostringstream output;
        PRINT_VALUES(output, 5, "red belt");
        ASSERT_EQUAL(output.str(), "5\nred belt\n");
    }, "PRINT_VALUES usage example");

    if (5 > 3) PRINT_VALUES(cout, 1, 2);

    if (3 > 10)
        PRINT_VALUES(cout, 3, 4);

    for (size_t i = 0; i != 1; ++i)
        PRINT_VALUES(cout, 5, 6);

    int count = 0;

    while(true) {
        if (true)
            PRINT_VALUES(cout, "TRUE", "TRUE");
        else
            break;

        ++count;
        if (count == 5) PRINT_VALUES(cout, "TRUE 5", "TRUE 5");

        if (count == 5)
            break;
    }

    return 0;
}

