#pragma once
#include "test_runner.h"

pair <string, string> SplitTwoStrict(string s, string delimiter);

pair <string, string> SplitTwo(string s, string delimiter);

string ReadToken(string& s, string delimiter);

int ConvertToInt(string str);

class Date {
    public:
        static Date FromString(string str) {
            const int year = ConvertToInt(ReadToken(str, "-"));
            const int month = ConvertToInt(ReadToken(str, "-"));
            const int day = ConvertToInt(str);
            return {year, month, day};
        }


    time_t AsTimeStamp () const ;

    private:
        int year_;
        int month_;
        int day_;

        Date(int year, int month, int day)
            : year_(year), month_(month), day_(day) {}
};

int ComputeDaysDiff(const Date& date_to, const Date& date_from);
