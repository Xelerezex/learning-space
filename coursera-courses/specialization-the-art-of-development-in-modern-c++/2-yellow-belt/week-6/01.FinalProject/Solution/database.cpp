#include "database.h"


// Methods & Constructors of class Date:
void Database::Add(Date& date, string& event) {
    DataBaseStorage[date].push_front(event);
}


DBType Database::GetAllData() {
    return DataBaseStorage;
}


// Not class member functions:
string ParseEvent(istream& is) {
    string line;
    getline(is, line);
    return line;
}
