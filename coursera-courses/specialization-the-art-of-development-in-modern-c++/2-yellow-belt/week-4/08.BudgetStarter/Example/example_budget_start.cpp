#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <chrono>

using namespace std;

pair<string, string> SplitTwoStrict(string s, string delimiter) {
  const size_t pos = s.find(delimiter);
  if (pos == s.npos) {
    return {s, ""};
  } else {
    return {s.substr(0, pos), s.substr(pos + delimiter.length())};
  }
}

pair<string, string> SplitTwo(string s, string delimiter) {
  const auto [lhs, rhs] = SplitTwoStrict(s, delimiter);
  return {lhs, rhs};
}

string ReadToken(string& s, string delimiter = " ") {
  const auto [lhs, rhs] = SplitTwo(s, delimiter);
  s = rhs;
  return lhs;
}

int ConvertToInt(string str) {
  size_t pos;
  const int result = stoi(string(str), &pos);
  if (pos != str.length()) {
    stringstream error;
    error << "string " << str << " contains " << (str.length() - pos) << " trailing chars";
    throw invalid_argument(error.str());
  }
  return result;
}

class Date {
public:
  static Date FromString(string str) {
    const int year = ConvertToInt(ReadToken(str, "-"));
    const int month = ConvertToInt(ReadToken(str, "-"));
    const int day = ConvertToInt(str);
    return {year, month, day};
  }

  // Weird legacy, can't wait for chrono::year_month_day
  time_t AsTimestamp() const {
    tm t;
    t.tm_sec  = 0;
    t.tm_min  = 0;
    t.tm_hour = 0;
    t.tm_mday = day_;
    t.tm_mon  = month_ - 1;
    t.tm_year = year_ - 1900;
    t.tm_isdst = 0;
    return mktime(&t);
  }

private:
  int year_;
  int month_;
  int day_;

  Date(int year, int month, int day)
    : year_(year), month_(month), day_(day) {}
};

int ComputeDaysDiff(const Date& date_to, const Date& date_from) {
  const time_t timestamp_to = date_to.AsTimestamp();
  const time_t timestamp_from = date_from.AsTimestamp();
  static constexpr int SECONDS_IN_DAY = 60 * 60 * 24;
  return (timestamp_to - timestamp_from) / SECONDS_IN_DAY;
}

static const Date START_DATE = Date::FromString("2000-01-01");
static const Date END_DATE = Date::FromString("2100-01-01");
static const size_t DAY_COUNT = ComputeDaysDiff(END_DATE, START_DATE);

int main() {
  cout.precision(25);
  vector<double> money(DAY_COUNT, .0);
  size_t num_queries;
  cin >> num_queries;

  for (size_t i = 0; i < num_queries; ++i) {
    string command, date_from, date_to;
    cin >> command >> date_from >> date_to;
    Date from = Date::FromString(date_from);
    Date to = Date::FromString(date_to);
    auto start_indx = ComputeDaysDiff(from, START_DATE);
    auto finish_indx = ComputeDaysDiff(to, START_DATE);
    if (command == "Earn") {
      double value;
      cin >> value;
      value /= ComputeDaysDiff(to, from) + 1;
      for (int j = start_indx; j <= finish_indx; ++j) {
        money[j] += value;
      }
    } else {
      cout << accumulate(money.begin() + start_indx, money.begin() + finish_indx + 1, 0.) << '\n';
    }
  }

  return 0;
}
