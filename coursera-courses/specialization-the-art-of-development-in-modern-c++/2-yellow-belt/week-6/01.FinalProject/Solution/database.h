#pragma once


#include "headers.h"
#include "date.h"

using DBType = map<Date, deque<string>>;

class Database {
    public:
        void Add(const Date& date, const string& event);
        DBType GetAllData() const;
    private:
        DBType DataBaseStorage;
};

string ParseEvent(istream& is);
