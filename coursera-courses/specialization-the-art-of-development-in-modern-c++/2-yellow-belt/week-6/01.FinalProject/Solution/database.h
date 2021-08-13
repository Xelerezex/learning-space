#pragma once

#include "headers.h"
#include "date.h"


// Usings:
using DBType = map<Date, vector<string>>;


// Operators:
ostream& operator << (ostream& os, const DBType& DB);

bool operator < (const pair<Date, vector<string>>& pr, const Date& date);

bool operator < (const Date& date, const pair<Date, vector<string>>& pr);


// Class & methods:
class Database {
    public:
        void Add(const Date& date, const string& event);
        void Print(ostream& os) const;

        template <typename Func>
        int RemoveIf(Func eval);

        template <typename Func>
        vector<string> FindIf(Func func) const;

        string Last(const Date& date) const;

        DBType GetAllData() const;

    private:
        DBType DataBaseStorage;
        map<Date, set<string>> Temporary;
};


template <typename Func>
int Database::RemoveIf(Func func) {
    unsigned number_out = 0;


    for (auto db_iter = DataBaseStorage.begin(); db_iter != DataBaseStorage.end();) {
        // db_iter->first equals: Date type, obj: our date from Date Class
        // db_iter->second equals: vector<string> type, obj: our vector with events

        size_t old_size = (db_iter->second).size();

        auto lrem_it = stable_partition((db_iter->second).begin(), (db_iter->second).end(), [date1=(db_iter->first), func](const string& event){
            return func(date1, event);
        });


        for (auto setr = (db_iter->second).begin(); setr != lrem_it; ++setr) {
            Temporary[db_iter->first].erase(*setr);
        }


        (db_iter->second).erase((db_iter->second).begin(), lrem_it);
        number_out += static_cast<unsigned>(old_size - (db_iter->second).size());


        if(db_iter->second.empty()) {
            Temporary.erase(db_iter->first);
            db_iter = DataBaseStorage.erase(db_iter);
        } else {
            ++db_iter;
        }
    }

    return number_out;
}


template <typename Func>
vector<string> Database::FindIf(Func func) const {
    vector<string> output;

    for (const auto& [date, events] : DataBaseStorage) {
        vector<string> temporary;
        copy_if(events.begin(), events.end(), back_inserter(temporary), [date1=date, func](const string& event){
            return func(date1, event);
        });

        for (const auto& event : temporary) {
            ostringstream topush;
            topush << date << ' ' << event;
            output.push_back(topush.str());
        }
    }

    return output;
}


// Outside Functions:
string ParseEvent(istream& is);
