#include "timer.h"

void TimerObjAppend() {
    Budget b;

    string fdate = "2020-02-26", sdate = "2020-03-01";

    double amount = 10;

    b.budgetAppend(fdate, sdate, amount);
}

void TimerObjAppendCount() {
    Budget b;

    string fdate = "2020-02-26", sdate = "2020-03-01";

    double amount = 10;

    b.budgetAppend(fdate, sdate, amount);
    b.budgetCount(fdate, sdate);
}

void TimerObjAppendCountAbsFuckingHuge() {
    Budget b;

    string fdate = "2000-01-01", sdate = "2099-12-31";

    double amount = 100'000'000;

    b.budgetAppend(fdate, sdate, amount);
    b.budgetCount(fdate, sdate);
}

void TimerAll() {
    cerr << "------------------Timer------------------------" << endl;
    Timer t;
    t.funcTimer(TimerObjAppend, "4 Date append");
    t.funcTimer(TimerObjAppendCount, "4 Date append & Count");
    t.funcTimer(TimerObjAppendCountAbsFuckingHuge, "MAX possible Date append & Count");
    cerr << "----------------------------------------------" << endl << endl;
}
