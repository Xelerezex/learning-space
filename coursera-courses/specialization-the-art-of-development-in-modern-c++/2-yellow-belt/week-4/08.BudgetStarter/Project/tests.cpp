#include "tests.h"

void TestClassDateOutput() {
    {
        Date date(2000, 12, 03);
        string expected = "2000-12-03";

        AssertEqual(date.getOutput(), expected, "Testing Our Data Class #1");
    }
    {
        Date date(2000, 9, 12);
        string expected = "2000-09-12";

        AssertEqual(date.getOutput(), expected, "Testing Our Data Class #2");
    }

}

void TestClassDateplusDay() {
    {
        Date date(2000, 9, 12);
        date.plusDay();
        string expected = "2000-09-13";

        AssertEqual(date.getOutput(), expected, "Testing Our Data Class. plusDay Function #1");
    }
    {
        Date date(2000, 9, 30);
        date.plusDay();
        string expected = "2000-10-01";

        AssertEqual(date.getOutput(), expected, "Testing Our Data Class. plusDay Function #2");
    }
    {
        Date date(2020, 12, 30);
        date.plusDay();
        string expected = "2020-12-31";

        AssertEqual(date.getOutput(), expected, "Testing Our Data Class. plusDay Function #3");
    }
    {
        Date date(2020, 12, 31);
        date.plusDay();
        string expected = "2021-01-01";

        AssertEqual(date.getOutput(), expected, "Testing Our Data Class. plusDay Function #4");
    }
    {
        Date date(2020, 02, 28);
        date.plusDay();
        string expected = "2020-02-29";

        AssertEqual(date.getOutput(), expected, "Testing Our Data Class. plusDay Function #5");
    }
    {
        Date date(2020, 02, 29);
        date.plusDay();
        string expected = "2020-03-01";

        AssertEqual(date.getOutput(), expected, "Testing Our Data Class. plusDay Function #6");
    }
        {
        Date date(2021, 02, 28);
        date.plusDay();
        string expected = "2021-03-01";

        AssertEqual(date.getOutput(), expected, "Testing Our Data Class. plusDay Function #7");
    }
}

void TestClassBudgetEarn() {
    using budgMap = map<string, double>;
    {
        Budget b;

        string fdate = "2020-02-26", sdate = "2020-03-01";

        double amount = 10;

        budgMap expected = {
            {"2020-02-26", 2},
            {"2020-02-27", 2},
            {"2020-02-28", 2},
            {"2020-02-29", 2},
            {"2020-03-01", 2},
        };

        b.budgetAppend(fdate, sdate, amount);
        AssertEqual(b.getBudgetData(), expected, "Testing Our Budget Class. Earn logic #1");
    }

}

void TestClassBudgetCompute() {
    {
        Budget b;

        string fdate = "2020-02-26", sdate = "2020-03-01";

        double amount = 10;

        double expected = 10;

        b.budgetAppend(fdate, sdate, amount);

        AssertEqual(b.budgetCount(fdate, sdate), expected, "Testing Our Budget Class. Compute logic #1");
    }

}

void TestAll() {
    cerr << "------------------Tests-----------------------" << endl;
    TestRunner tr;
    tr.RunTest(TestClassDateOutput, "Data class Test");
    tr.RunTest(TestClassDateplusDay, "Data class Test. plusDay Function");
    tr.RunTest(TestClassBudgetEarn, "Budget class Test. Earn logic");
    tr.RunTest(TestClassBudgetCompute, "Budget class Test. Compute logic");
    cerr << "----------------------------------------------" << endl << endl;
}
