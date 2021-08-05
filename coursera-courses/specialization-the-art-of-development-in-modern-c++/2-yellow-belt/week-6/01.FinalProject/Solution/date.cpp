#include "date.h"

// Methods & Constructors of class Date:
Date::Date(const int& y, const int& m, const int& d) :
        Year(y),
        Month([m] {
            if (m > 12 || m < 1) {
                throw logic_error("Month value is invalid: " + to_string(m));
            } else {
                return m;
            }
        }() ),
        Day([d] {
            if (d > 31 || d < 1) {
                throw logic_error("Day value is invalid: " + to_string(d));
            } else {
                return d;
            }
        }() ) {/*cout << "Works Well" << endl;*/}


int Date::GetYear() const {
    return Year;
}


int Date::GetMonth() const {
    return Month;
}


int Date::GetDay() const {
    return Day;
}


// Class operator's redefinitions:
ostream& operator<<(ostream& stream, const Date& date) {
    return  stream << setw(4) << setfill('0') << date.GetYear() <<
               "-" << setw(2) << setfill('0') << date.GetMonth() <<
               "-" << setw(2) << setfill('0') << date.GetDay();
}


bool operator<(const Date& lhs, const Date& rhs) {
    return  vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
            vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}


// Not class member functions:
Date ParseDate(const string& date) {
    istringstream date_stream(date);
    bool ok = true;

    int year;
    ok = ok && (date_stream >> year);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int month;
    ok = ok && (date_stream >> month);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int day;
    ok = ok && (date_stream >> day);
    ok = ok && date_stream.eof();

    if (!ok) {
      throw logic_error("Wrong date format: " + date);
    }
    return Date(year, month, day);
}
