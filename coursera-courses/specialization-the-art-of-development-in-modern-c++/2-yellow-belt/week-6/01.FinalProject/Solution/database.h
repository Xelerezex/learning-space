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
        vector<string> FindIf(Func func) const;

        template <typename Date>
        string Last(const Date& date) const;

        DBType GetAllData() const;
    private:
        DBType DataBaseStorage;
};

bool operator < (const pair<Date, vector<string>>& pr, const Date& date);

bool operator < (const Date& date, const pair<Date, vector<string>>& pr);

template <typename Date>
string Database::Last(const Date& date) const {
    ostringstream os;
    os << date;

    auto it = upper_bound(DataBaseStorage.begin(), DataBaseStorage.end(), date);   // First element that equals date or bigger

    bool cond1 = it == DataBaseStorage.begin();
    bool cond2 = date < (it->first);
    bool cond3 = it == DataBaseStorage.end();
    //bool cond4  = date == ((--it)->first)

    if ((!cond1 && cond2) || (!cond1 && cond3)) {
        ostringstream temporary;
        Date tempdate = (--it)->first;
        temporary << tempdate << " " << DataBaseStorage.at(tempdate).back();

        return temporary.str();
    }
    else {
        //                            !!
        throw invalid_argument(os.str() + "<---!!!");
    }
}


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

ostream& operator << (ostream& os, const DBType& DB);

string ParseEvent(istream& is);
