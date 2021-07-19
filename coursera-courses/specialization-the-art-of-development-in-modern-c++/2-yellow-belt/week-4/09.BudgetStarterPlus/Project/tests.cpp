#include "tests.h"

void TestSplitTwoStrict() {
    {
        string str = "20000-1000-100", delimiter = "-";
        pair <string, string> expected = {"20000", "1000-100"};

        AssertEqual(SplitTwoStrict(str, delimiter), expected, "Testing SplitTwoStrict() function. Test #1");
    }
    {
        string str = "10000", delimiter = "-";
        pair <string, string> expected = {"10000", ""};

        AssertEqual(SplitTwoStrict(str, delimiter), expected, "Testing SplitTwoStrict() function. Test #2");
    }
    {
        string str = "10+10+100+1000+abc", delimiter = "+";
        pair <string, string> expected = {"10", "10+100+1000+abc"};

        AssertEqual(SplitTwoStrict(str, delimiter), expected, "Testing SplitTwoStrict() function. Test #3");
    }
    {
        string str = "a:b:c", delimiter = ":";
        pair <string, string> expected = {"a", "b:c"};

        AssertEqual(SplitTwoStrict(str, delimiter), expected, "Testing SplitTwoStrict() function. Test #4");
    }
}

void TestSplitTwo() {
    {
        string str = "20000-1000-100", delimiter = "-";
        pair <string, string> expected = {"20000", "1000-100"};

        AssertEqual(SplitTwo(str, delimiter), expected, "Testing SplitTwoStrict() function. Test #1");
    }
    {
        string str = "10000", delimiter = "-";
        pair <string, string> expected = {"10000", ""};

        AssertEqual(SplitTwo(str, delimiter), expected, "Testing SplitTwoStrict() function. Test #2");
    }
    {
        string str = "a:b:c", delimiter = ":";
        pair <string, string> expected = {"a", "b:c"};

        AssertEqual(SplitTwo(str, delimiter), expected, "Testing SplitTwoStrict() function. Test #3");
    }
}

void TestReadToken() {
    {
        string delimiter = ":";

        string str = "a:b:c", expected_str = "b:c";

        string input = ReadToken(str, delimiter), expected = "a";

        AssertEqual(input, expected, "Testing SplitTwoStrict() function. Test Function #1.0");
        AssertEqual(str, expected_str, "Testing SplitTwoStrict() function. Test Delimiter #1.1");
    }
    {
        string str = "cccc", expected_str = "";

        string input = ReadToken(str, " "), expected = "cccc";

        AssertEqual(input, expected, "Testing SplitTwoStrict() function. Test Function #2.0");
        AssertEqual(str, expected_str, "Testing SplitTwoStrict() function. Test Delimiter #2.1");
    }
}

void TestConvertToInt() {
    {
        int expected = 100;

        AssertEqual(ConvertToInt("100"), expected, "Testing ConvertToInt() function. Test #1");
    }
    {
        int expected = 100;
        string str = "100---";

        AssertEqual(ConvertToInt(ReadToken(str, "-")), expected, "Testing ConvertToInt() function. Test #2");
    }
}

void TestDate() {
    {
        Date date = Date::FromString("1971-01-01");
        const time_t time = date.AsTimeStamp(), expected = 364;

        AssertEqual((time / (60 * 60 * 24)) , expected, "Testing Date class. Test #1");
    }
}

void TestComputeDaysDiff() {
    {
        Date date1 = Date::FromString("1971-01-01");
        Date date2 = Date::FromString("1972-01-01");

        int expected = 365;

        AssertEqual(ComputeDaysDiff(date2, date1), expected, "Testing Date class. Test #1");
    }

    {
        Date date1 = Date::FromString("2020-01-01");
        Date date2 = Date::FromString("2021-01-01");

        int expected = 366;

        AssertEqual(ComputeDaysDiff(date2, date1), expected, "Testing Date class. Test #2");

    }
}

void TestAll() {
    cerr << "------------------Tests-----------------------" << endl;
    TestRunner tr;
    tr.RunTest(TestSplitTwoStrict, "Testing SplitTwoStrict() function");
    tr.RunTest(TestSplitTwo, "Testing SplitTwo() function");
    tr.RunTest(TestReadToken, "Testing ReadToken() function");
    tr.RunTest(TestDate, "Testing Date class");
    tr.RunTest(TestComputeDaysDiff, "Testing TestComputeDaysDiff() function");
    cerr << "----------------------------------------------" << endl << endl;
}
