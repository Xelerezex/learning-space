#include "database.h"


// Methods & Constructors of class Date:
void Database::Add(const Date& date, const string& event) {
    auto cont_begin = begin(DataBaseStorage);
    auto cont_end = end(DataBaseStorage);
    //pair<Date, string> datevent = make_pair(date, event);


    bool condition1 = (find(cont_begin, cont_end, make_pair(date, event)) == cont_end);
    if (condition1) {
        DataBaseStorage.emplace_back(date, event);

        /// !!!!!!!!!!!!!!!!!!!!!!!! HERE
        sort(cont_begin, cont_end, [](const pair<Date, string> &left, const pair<Date, string> &right) {
             return left.first < right.first;
        });
    }
}


void Database::Print(ostream& os) const {
    os << DataBaseStorage;
}


DBType Database::GetAllData() const {
    return DataBaseStorage;
}

// Class operator's redefinitions:
ostream& operator << (ostream& os, const DBType& DB) {
    for (const auto& [data, event] : DB) {
        os << data << " " << event << endl;
    }
    return os;
}

// Not class member functions:
string ParseEvent(istream& is) {
    is >> ws;
    string line;
    getline(is, line);
    return line;
}
