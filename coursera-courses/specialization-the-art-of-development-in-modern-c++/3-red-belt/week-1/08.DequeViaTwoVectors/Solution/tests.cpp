#include "tests.h"


void TestTest() {
    ASSERT_EQUAL(true, true);
}


void TestAll() {
    cerr << "------------------Tests-----------------------" << endl;
    TestRunner tr;

    RUN_TEST(tr, TestTest);

    cerr << "----------------------------------------------" << endl << endl;
}
