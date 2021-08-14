#include "database.h"


// Class operator's redefinitions:
ostream& operator << (ostream& os, const DBType& DB) {
    for (const auto& [data, event] : DB) {
        for (const auto& item : event ) {
            os << data << " " << item << '\n';
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

    auto input = Temporary[date].insert(event);
    if (input.second == true) {
        DataBaseStorage[date].push_back(event);
    }

}

string Database::Last(const Date& date) const {
    ostringstream os;
    os << date;

    auto it = DataBaseStorage.upper_bound(date);   // First element that bigger than date or end()

    bool cond1 = it == DataBaseStorage.begin();

    if (!cond1) {
        ostringstream temporary;
        Date tempdate = (--it)->first;

        temporary << tempdate << " " << DataBaseStorage.at(tempdate).back();

        return temporary.str();
    }
    else {
        throw invalid_argument("");
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
