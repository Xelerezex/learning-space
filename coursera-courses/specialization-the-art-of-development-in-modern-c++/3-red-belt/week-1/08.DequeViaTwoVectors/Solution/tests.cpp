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

        vector<string> expectedFront = {"one", "DICK"};
        vector<string> expectedBack = {"two", "three", "four"};

        ASSERT_EQUAL(dq.GetVectorFront(), expectedFront);
        ASSERT_EQUAL(dq.GetVectorBack(), expectedBack);
        ASSERT_EQUAL(dq.Size(), 5u);
        ASSERT_EQUAL(dq.Empty(), false);
    }
}

void TestBackFront() {
    {
        Deque<string> dq;


        dq.PushBack("two");           // {two}
        dq.PushFront("one");          // {one, two}
        dq.PushBack("three");         // {one, two, three}
        dq.PushBack("four");          // {one, two, three, four}
        dq.PushFront("DICK");         // {DICK, one, two, three, four}

        string expectedFront = "DICK";
        string expectedBack = "four";

        ASSERT_EQUAL(dq.Front(), expectedFront);
        ASSERT_EQUAL(dq.Back(), expectedBack);

        dq.Front() = "FIRST";
        dq.Back() = "LAST";          // {FIRST, one, two, three, LAST}
        string expectedFrontNew = "FIRST";
        string expectedBackNew = "LAST";

        ASSERT_EQUAL(dq.Front(), expectedFrontNew);
        ASSERT_EQUAL(dq.Back(), expectedBackNew);

        ASSERT_EQUAL(dq.Size(), 5u);
        ASSERT_EQUAL(dq.Empty(), false);
    }
    {
        Deque<string> dq;
        dq.PushBack("One");
        dq.PushBack("Two");

        ASSERT_EQUAL(dq.Front(), "One");
        ASSERT_EQUAL(dq.Back(), "Two");
    }
}

void TestOperator() {
    Deque<string> dq;
    dq.PushBack("two");           // {two}
    dq.PushFront("one");          // {one, two}
    dq.PushBack("three");         // {one, two, three}
    dq.PushBack("four");          // {one, two, three, four}
    dq.PushFront("DICK");         // {DICK, one, two, three, four} : {one, DICK} & {four, three, two};
    {
        string expectedOp = "DICK";
        string testing = dq[0];

        ASSERT_EQUAL(testing, expectedOp);
    }
    {
        string expectedOp = "one";
        string testing = dq[1];

        ASSERT_EQUAL(testing, expectedOp);
    }
   {
        string expectedOp = "two";
        string testing = dq[2];

        ASSERT_EQUAL(testing, expectedOp);
    }
    {
        string expectedOp = "three";
        string testing = dq[3];

        ASSERT_EQUAL(testing, expectedOp);
    }
    {
        string expectedOp = "four";
        string testing = dq[4];

        ASSERT_EQUAL(testing, expectedOp);
    }
    {
        ASSERT_EQUAL(dq.Size(), 5u);
        ASSERT_EQUAL(dq.Empty(), false);
    }
    {
        Deque<string> dqq;
        dqq.PushBack("One");
        dqq.PushBack("Two");
        dqq.PushBack("Three");

        ASSERT_EQUAL(dqq[0], "One");
        ASSERT_EQUAL(dqq[1], "Two");
        ASSERT_EQUAL(dqq[2], "Three");
    }
    {
        Deque<string> dqq;
        dqq.PushFront("One");
        dqq.PushFront("Two");
        dqq.PushFront("Three");

        ASSERT_EQUAL(dqq[0], "Three");
        ASSERT_EQUAL(dqq[1], "Two");
        ASSERT_EQUAL(dqq[2], "One");
    }
    {
        string expectedOp = "DICK_D";
        dq[0] = "DICK_D";

        ASSERT_EQUAL(dq[0], expectedOp);
    }
    {
        string expectedOp = "FOUR";
        dq[4] = "FOUR";

        ASSERT_EQUAL(dq[4], expectedOp);
    }
}

void TestAt() {
    Deque<string> dq;
    dq.PushBack("two");           // {two}
    dq.PushFront("one");          // {one, two}
    dq.PushBack("three");         // {one, two, three}
    dq.PushBack("four");          // {one, two, three, four}
    dq.PushFront("DICK");         // {DICK, one, two, three, four} : {one, DICK} & {four, three, two};
    {
        dq.At(0) = "dick";
        ASSERT_EQUAL(dq.At(0), "dick");
        ASSERT_EQUAL(dq.At(1), "one");
        ASSERT_EQUAL(dq.At(2), "two");
        ASSERT_EQUAL(dq.At(3), "three");
        ASSERT_EQUAL(dq.At(4), "four");
        try{
            dq.At(5) = "five";
            ASSERT_EQUAL(false, true);
        } catch(exception& ex) {}
        try{
            dq.At(-1) = "minuw one";
            ASSERT_EQUAL(false, true);
        } catch(exception& ex) {}
    }


}

void TestAll() {
    cerr << "------------------Tests-----------------------" << endl;
    TestRunner tr;

    RUN_TEST(tr, TestBasic);
    RUN_TEST(tr, TestEmptySize);
    RUN_TEST(tr, TestPushBackFront);
    RUN_TEST(tr, TestBackFront);
    RUN_TEST(tr, TestOperator);
    RUN_TEST(tr, TestAt);

    cerr << "----------------------------------------------" << endl << endl;
}
