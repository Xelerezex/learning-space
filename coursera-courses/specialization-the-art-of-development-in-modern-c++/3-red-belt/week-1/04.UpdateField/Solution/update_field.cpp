#include "airline_ticket.h"
#include "test_runner.h"

using namespace std;


bool operator == (const Date& ldate, const Date& rdate) {
    return make_tuple(ldate.year, ldate.month, ldate.day) ==
           make_tuple(rdate.year, rdate.month, rdate.day);
}

bool operator != (const Date& ldate, const Date& rdate) {
    return make_tuple(ldate.year, ldate.month, ldate.day) !=
           make_tuple(rdate.year, rdate.month, rdate.day);
}

bool operator < (const Date& ldate, const Date& rdate) {
    return make_tuple(ldate.year, ldate.month, ldate.day) <
           make_tuple(rdate.year, rdate.month, rdate.day);
}

ostream& operator << (ostream& os, const Date& date) {
    return os << date.year << "-" << date.month << "-" << date.day << '\n';
}

istream& operator >> (istream& is, Date& date) {
    is >> date.year;
    is.ignore(1);
    is >> date.month;
    is.ignore(1);
    is >> date.day;
    return is;
}

bool operator == (const Time& ltime, const Time& rtime) {
    return make_tuple(ltime.hours, ltime.minutes) ==
           make_tuple(rtime.hours, rtime.minutes);
}

bool operator != (const Time& ltime, const Time& rtime) {
    return make_tuple(ltime.hours, ltime.minutes) !=
           make_tuple(rtime.hours, rtime.minutes);
}

bool operator < (const Time& ltime, const Time& rtime) {
    return make_tuple(ltime.hours, ltime.minutes) <
           make_tuple(rtime.hours, rtime.minutes);
}

ostream& operator << (ostream& os, const Time& time) {
    return os << time.hours << ":" << time.minutes << '\n';
}

istream& operator >> (istream& is, Time& time) {
    is >> time.hours;
    is.ignore(1);
    is >> time.minutes;
    return is;
}

#define UPDATE_FIELD(ticket, field, values) {     \
    auto it = values.find(#field);                \
    if (it != values.end()) {                     \
        istringstream is(it->second);             \
        is >> ticket.field;                       \
    }                                             \
}


void TestUpdate() {
  AirlineTicket t;
  t.price = 0;

  const map<string, string> updates1 = {
    {"departure_date", "2018-2-28"},
    {"departure_time", "17:40"},
  };
  UPDATE_FIELD(t, departure_date, updates1);
  UPDATE_FIELD(t, departure_time, updates1);
  UPDATE_FIELD(t, price, updates1);

  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 0);

  const map<string, string> updates2 = {
    {"price", "12550"},
    {"arrival_time", "20:33"},
  };
  UPDATE_FIELD(t, departure_date, updates2);
  UPDATE_FIELD(t, departure_time, updates2);
  UPDATE_FIELD(t, arrival_time, updates2);
  UPDATE_FIELD(t, price, updates2);

  // updates2 не содержит ключей "departure_date" и "departure_time", поэтому
  // значения этих полей не должны измениться
  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 12550);
  ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestUpdate);
}
