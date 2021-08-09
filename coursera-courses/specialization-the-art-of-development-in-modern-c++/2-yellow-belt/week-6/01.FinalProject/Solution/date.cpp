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


bool operator < (const Date& lhs, const Date& rhs) {
    return  make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay())
        <   make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}


bool operator <= (const Date& lhs, const Date& rhs) {
    return  make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay())
        <=   make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}


bool operator > (const Date& lhs, const Date& rhs) {
    return  make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay())
        >   make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}


bool operator >= (const Date& lhs, const Date& rhs) {
    return  make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay())
        >=   make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}


bool operator == (const Date& lhs, const Date& rhs) {
    return  make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay())
        ==   make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}


bool operator != (const Date& lhs, const Date& rhs) {
    return  make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay())
        !=   make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}


// Not class member functions:
Date ParseDate(istream& date_stream) {
    bool ok = true;
    date_stream >> ws;

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
    ok = ok && (date_stream.eof() || date_stream.peek() == ' ');

    if (!ok) {
        throw logic_error("Wrong date format.");
    }
    return Date(year, month, day);
}
