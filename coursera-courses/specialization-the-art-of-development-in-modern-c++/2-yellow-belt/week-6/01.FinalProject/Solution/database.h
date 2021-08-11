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

        template <typename Func>
        vector<string> FindIf(Func func);

        DBType GetAllData() const;
    private:
        DBType DataBaseStorage;
};

template <typename Func>
int Database::RemoveIf(Func func) {
    int number_out = 0;

    for (auto& [date, events] : DataBaseStorage) {
        size_t old_size = events.size();

        auto it = stable_partition(events.begin(), events.end(), [date, func](const string& event){
            return func(date, event);
        });

        if (it != events.begin()) {
            events.erase(events.begin(), it);

            number_out += static_cast<int>(old_size - events.size());
        }
    }

    return number_out;
}

template <typename Func>
vector<string> Database::FindIf(Func func) {
    vector<string> output;

    for (auto& [date, events] : DataBaseStorage) {
        vector<string> temporary;
        copy_if(events.begin(), events.end(), back_inserter(temporary), [date, func](const string& event){
            return func(date, event);
        });

        for (const auto& event : temporary) {
            ostringstream topush;
            topush << date << " " << event;
            output.push_back(topush.str());
        }
    }

    return output;
}

ostream& operator << (ostream& os, const DBType& DB);

string ParseEvent(istream& is);
