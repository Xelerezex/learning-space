#ifndef DATE_H
#define DATE_H

#include <ctime>
#include <ostream>
#include <string>

#ifdef BUDGET_TEST
#include "budget_test.h"
#endif

class Date {
 public:
  Date(int year, int month, int day);

  time_t AsTimestamp() const;

  static bool Validate(int year, int month, int day);
  static Date FromString(const std::string& str);
  static int ComputeDaysDiff(const Date& date_to, const Date& date_from);
  static Date Next(const Date& date);

  int Year() const { return year_; }
  int Month() const { return month_; }
  int Day() const { return day_; }

  bool operator==(const Date& other) const;
  bool operator<(const Date& other) const;
  bool operator<=(const Date& other) const;

  static const std::string delim;

#ifdef BUDGET_TEST
  friend class TestDate;
#endif
 private:
  int day_;
  int month_;
  int year_;
};

std::ostream& operator<<(std::ostream& os, const Date& date);

#endif  // DATE_H
