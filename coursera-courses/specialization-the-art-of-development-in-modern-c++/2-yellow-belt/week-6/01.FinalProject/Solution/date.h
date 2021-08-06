#pragma once
#include "headers.h"

class Date {
public:
    // Constructors:
    Date(const int& y, const int& m, const int& d);

    // Getters:
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;

private:
    const int Year;
    const int Month;
    const int Day;
};

Date ParseDate(istream& date_stream);

ostream& operator<<(ostream& stream, const Date& date);

bool operator<(const Date& lhs, const Date& rhs);

bool operator == (const Date& lhs, const Date& rhs);

bool operator != (const Date& lhs, const Date& rhs);
