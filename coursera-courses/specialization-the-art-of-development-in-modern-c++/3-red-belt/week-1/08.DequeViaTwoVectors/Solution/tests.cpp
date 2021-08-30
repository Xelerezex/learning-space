#include "tests.h"


void TestBasic() {
    {   // Creating object
        try {
            Deque<int> dq;
        } catch(...) {
            ASSERT_EQUAL(true, false);
        }
    }
}


void TestEmptySize() {
    {
        Deque<int> dq;

        ASSERT_EQUAL(dq.Empty(), true);
    }
    {
        Deque<int> dq;

        ASSERT_EQUAL(dq.Size(), 0u);
    }
}


void TestPushBackFront() {
    {
        Deque<int> dq;

        dq.PushBack(0);
        dq.PushFront(0);

        ASSERT_EQUAL(dq.Size(), 2u);
    }
    {
        Deque<string> dq;


        dq.PushBack("two");           // {two}
        dq.PushFront("one");          // {one, two}
        dq.PushBack("three");         // {one, two, three}
        dq.PushBack("four");          // {one, two, three, four}
        dq.PushFront("DICK");         // {DICK, one, two, three, four}

        vector<string> expectedFront = {"DICK", "one"};
        vector<string> expectedBack = {"four", "three", "two"};

        ASSERT_EQUAL(dq.GetVectorFront(), expectedFront);
        ASSERT_EQUAL(dq.GetVectorBack(), expectedBack);
        ASSERT_EQUAL(dq.Size(), 5u);
        ASSERT_EQUAL(dq.Empty(), false);
    }
}


void TestAll() {
    cerr << "------------------Tests-----------------------" << endl;
    TestRunner tr;

    RUN_TEST(tr, TestBasic);
    RUN_TEST(tr, TestEmptySize);
    RUN_TEST(tr, TestPushBackFront);

    cerr << "----------------------------------------------" << endl << endl;
}
