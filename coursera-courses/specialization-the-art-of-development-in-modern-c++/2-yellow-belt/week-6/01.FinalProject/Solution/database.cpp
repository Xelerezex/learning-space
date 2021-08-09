#include "database.h"


// Methods & Constructors of class Date:
void Database::Add(const Date& date, const string& event) {
    bool condition1 = (find(begin(DataBaseStorage[date]),
                            end(DataBaseStorage[date]), event)
                         == end(DataBaseStorage[date]));

    bool condition2 = DataBaseStorage[date].empty();
    if (condition1 || condition2) {
        DataBaseStorage[date].push_back(event);
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
    for (const auto& [key, value] : DB) {
        for (auto it = value.begin(); it != value.end(); ++it) {
            os << key << " " << *it << endl;
        }
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
