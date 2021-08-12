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
    int number_out = 0;

    for (auto& [date, events] : DataBaseStorage) {
        size_t old_size = events.size();

        auto it = stable_partition(events.begin(), events.end(), [date1=date, func](const string& event){
            return func(date1, event);
        });

        if (it != events.begin()) {
            events.erase(events.begin(), it);

            number_out += static_cast<int>(old_size - events.size());
        }

        // Fixed not to delete from Temporary
        if (events.empty()) {
            Temporary[date].clear();
        }
    }

    for (auto iter = DataBaseStorage.begin(); iter != DataBaseStorage.end();) {
        if(iter->second.empty()) {
            iter = DataBaseStorage.erase(iter);
        } else {
            ++iter;
        }
    }

    return number_out;
}


template <typename Func>
vector<string> Database::FindIf(Func func) const {
    vector<string> output;

    for (auto& [date, events] : DataBaseStorage) {
        vector<string> temporary;
        copy_if(events.begin(), events.end(), back_inserter(temporary), [date1=date, func](const string& event){
            return func(date1, event);
        });

        for (const auto& event : temporary) {
            ostringstream topush;
            topush << date << " " << event;
            output.push_back(topush.str());
        }
    }

    return output;
}

// Outside Functions:
string ParseEvent(istream& is);
