#include "test.h"

void TestBasic() {

}

void TestAll() {
    cerr << "------------------Tests-----------------------" << endl;
    TestRunner tr;

    RUN_TEST(tr, TestBasic);

    cerr << "----------------------------------------------" << endl << endl;
}
