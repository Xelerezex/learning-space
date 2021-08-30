#include "tests.h"



void TestBasic() {
    {
        ASSERT_EQUAL(true, false);
    }
}


void TestAll() {
    cerr << "------------------Tests-----------------------" << endl;
    TestRunner tr;

    RUN_TEST(tr, TestBasic);

    cerr << "----------------------------------------------" << endl << endl;
}
