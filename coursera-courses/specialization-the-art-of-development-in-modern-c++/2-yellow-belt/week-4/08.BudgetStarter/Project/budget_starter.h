#pragma once
#include "test_runner.h"
using namespace std;

class Date{
    public:
        Date(int, int, int);
        Date(string& str, string delimiter);

        int getYear() const;
        int getMonth() const;
        int getDay() const;
        string getOutput() const;

        void plusDay();

    private:
        int Year;
        int Month;
        int Day;
};


class Budget{
    public:
        map<string, double> getBudgetData() const;

        void budgetAppend(string& fdate, string& sdate, double amount);

        double initBudget(string& fdate, string& sdate);

        double budgetCount(string& fdate, string& sdate);

    private:
        map<string, double> budgetData;
};

