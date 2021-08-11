#pragma once


#include "headers.h"
#include "date.h"

//
using DBType = map<Date, vector<string>>;

class Database {
    public:
        void Add(const Date& date, const string& event);
        void Print(ostream& os) const;

        template <typename Func>
        int RemoveIf(Func eval);

        DBType GetAllData() const;
    private:
        DBType DataBaseStorage;
};

template <typename Func>
int Database::RemoveIf(Func func) {
    int number_out = 1;

    // auto DB_citer = DataBaseStorage.cbegin();
    // auto DB_cend = DataBaseStorage.cend();


    return number_out;
}

ostream& operator << (ostream& os, const DBType& DB);

string ParseEvent(istream& is);
