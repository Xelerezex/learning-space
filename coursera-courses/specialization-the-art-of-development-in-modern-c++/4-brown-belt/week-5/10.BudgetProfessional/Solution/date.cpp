#include "date.h"

#include <sstream>

using namespace std;

static const int SECONDS_IN_DAY = 60 * 60 * 24;

int Date::ComputeDaysDiff(const Date& date_to, const Date& date_from) {
  const time_t timestamp_to = date_to.AsTimestamp();
  const time_t timestamp_from = date_from.AsTimestamp();
  return (timestamp_to - timestamp_from) / SECONDS_IN_DAY;
}

Date Date::Next(const Date& date) {
  const time_t next_day_ts = date.AsTimestamp() + SECONDS_IN_DAY;
  const tm* next_day = localtime(&next_day_ts);
  return {1900 + next_day->tm_year, 1 + next_day->tm_mon, next_day->tm_mday};
}

Date::Date(int year, int month, int day) {
  if (!Validate(year, month, day)) {
    const string bad_date =
        to_string(year) + delim + to_string(month) + delim + to_string(day);
    throw std::domain_error("Wrong date format: " + bad_date);
  }
  year_ = year;
  month_ = month;
  day_ = day;
}

time_t Date::AsTimestamp() const {
  std::tm t;
  t.tm_sec = 0;
  t.tm_min = 0;
  t.tm_hour = 0;
  t.tm_mday = day_;
  t.tm_mon = month_ - 1;
  t.tm_year = year_ - 1900;
  t.tm_isdst = 0;
  return mktime(&t);
}

bool Date::Validate(int year, int month, int day) {
  if (month == 2 && day == 29) {
    return year % 4 == 0;
  }

  return (year >= 2000 && year <= 2099 && month >= 1 && month <= 12 &&
          day >= 1 && day <= 31) ||
         (year == 2100 && month == 1 && day == 1);
}

Date Date::FromString(const std::string& str) {
  istringstream in{str};
  int year, month, day;

  in >> year;
  in.ignore(1);
  in >> month;
  in.ignore(1);
  in >> day;

  return {year, month, day};
}

const std::string Date::delim = "-";

bool Date::operator==(const Date& other) const {
  return year_ == other.year_ && month_ == other.month_ && day_ == other.day_;
}

bool Date::operator<(const Date& other) const {
  return Date::ComputeDaysDiff(other, *this) > 0;
}

bool Date::operator<=(const Date& other) const {
  return Date::ComputeDaysDiff(other, *this) >= 0;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
  return os << date.Year() << Date::delim << date.Month() << Date::delim
            << date.Day();
}
