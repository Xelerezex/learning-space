#pragma once


#include "headers.h"
#include "date.h"

using DBType = map<Date, deque<string>>;

class Database {
    public:
        void Add(const Date& date, const string& event);
        void Print(ostream& os) const;

        DBType GetAllData() const;
    private:
        DBType DataBaseStorage;
};

ostream& operator << (ostream& os, const DBType& DB);


string ParseEvent(istream& is);
