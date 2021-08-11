#include "database.h"


// Methods & Constructors of class Date:
void Database::Add(const Date& date, const string& event) {
    auto cont_begin = begin(DataBaseStorage[date]);
    auto cont_end = end(DataBaseStorage[date]);
    //pair<Date, string> datevent = make_pair(date, event);


    bool condition1 = (find(cont_begin, cont_end, event) == cont_end);
    bool condition2 = (DataBaseStorage[date]).empty();

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
    for (const auto& [data, event] : DB) {
        if (!event.empty()) {
            for (const auto& item : event ){
                os << data << " " << item << endl;
            }
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
