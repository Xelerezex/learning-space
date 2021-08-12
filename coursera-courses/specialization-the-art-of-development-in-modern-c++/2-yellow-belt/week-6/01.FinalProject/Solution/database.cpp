#include "database.h"


// Class operator's redefinitions:
ostream& operator << (ostream& os, const DBType& DB) {
    for (const auto& [data, event] : DB) {
        for (const auto& item : event ) {
            os << data << " " << item << endl;
        }
    }
    return os;
}

bool operator < (const pair<Date, vector<string>>& pr, const Date& date) {
    return pr.first < date;
}

bool operator < (const Date& date, const pair<Date, vector<string>>& pr) {
    return date < pr.first;
}


// Methods & Constructors of class Date:
void Database::Add(const Date& date, const string& event) {
    auto cont_begin = begin(DataBaseStorage[date]);
    auto cont_end = end(DataBaseStorage[date]);
    //pair<Date, string> datevent = make_pair(date, event);

    //                !!!!!
    bool condition1 = (find(cont_begin, cont_end, event) == cont_end);
    bool condition2 = (DataBaseStorage[date]).empty();

    if (condition1 || condition2) {
        DataBaseStorage[date].push_back(event);
    }
}

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

void Database::Print(ostream& os) const {
    os << DataBaseStorage;
}


// Not class member functions:
string ParseEvent(istream& is) {
    is >> ws;
    string line;
    getline(is, line);
    return line;
}
