#pragma once


#include "headers.h"
#include "date.h"

using DBType = map<Date, deque<string>>;

class Database {
    public:
        void Add(Date& date, string& event);
        DBType GetAllData();
    private:
        DBType DataBaseStorage;
};

string ParseEvent(istream& is);
