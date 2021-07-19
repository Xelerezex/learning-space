#include "timer.h"

void TimerSplitTwoStrict() {
    string str = "20000-1000-100", delimiter = "-";
    pair <string, string> expected = {"20000", "1000-100"};

    const auto output = SplitTwoStrict(str, delimiter);
}

void TimerSplitTwo() {
    string str = "20000-1000-100", delimiter = "-";
    pair <string, string> expected = {"20000", "1000-100"};

    const auto output = SplitTwo(str, delimiter);
}

void TimerReadToken(){
    {
        string delimiter = ":";

        string str = "a:b:c", expected_str = "b:c";

        string input = ReadToken(str, delimiter), expected = "a";

        AssertEqual(input, expected, "Testing SplitTwoStrict() function. Test Function #1.0");
        AssertEqual(str, expected_str, "Testing SplitTwoStrict() function. Test Delimiter #1.1");
    }
}
void TimerConvertToInt(){
    {
        int expected = 100;
        string str = "100---";
        AssertEqual(ConvertToInt(ReadToken(str, "-")), expected, "Testing ConvertToInt() function. Test #2");
    }
}

void TimerDate() {
    {
            Date date = Date::FromString("2020-10-20");
            const time_t time = date.AsTimeStamp();
            int z = time + time;
            z = z + 1;
    }
}

void TimerComputeDaysDiff() {
    {

    }
}
void TimerAll() {
    cerr << "------------------Timer------------------------" << endl;
    Timer t;
    t.FuncTimer(TimerSplitTwoStrict, "Timing SplitTwoStrict() function. Time #1");
    t.FuncTimer(TimerSplitTwo, "Timing SplitTwo() function. Time #2");
    t.FuncTimer(TimerReadToken, "Timing ReadToken() function. Time #3");
    t.FuncTimer(TimerDate, "Testing Date class. Time #4");
    t.FuncTimer(TimerComputeDaysDiff, "Testing Date class. Time #5");
    cerr << "----------------------------------------------" << endl << endl;
}
