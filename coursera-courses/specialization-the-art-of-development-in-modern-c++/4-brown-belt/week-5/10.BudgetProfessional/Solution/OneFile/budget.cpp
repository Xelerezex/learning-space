#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <string>
#include <string_view>
#include <ctime>
#include <map>
#include <utility>
#include <vector>
#include <cstddef>
#include <iterator>
#include <numeric>
#include <stdexcept>

using namespace std;

static const int SECONDS_IN_DAY = 60 * 60 * 24;

class Date {
  public:
  Date(int year, int month, int day) {
    if (!Validate(year, month, day)) {
      const string bad_date =
          to_string(year) + delim + to_string(month) + delim + to_string(day);
      throw std::domain_error("Wrong date format: " + bad_date);
    }
    year_ = year;
    month_ = month;
    day_ = day;
  }

  time_t AsTimestamp() const {
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

  static bool Validate(int year, int month, int day) {
    if (month == 2 && day == 29) {
      return year % 4 == 0;
    }

    return (year >= 2000 && year <= 2099 && month >= 1 && month <= 12 &&
            day >= 1 && day <= 31) ||
           (year == 2100 && month == 1 && day == 1);
  }

  static Date FromString(const std::string& str) {
    istringstream in{str};
    int year, month, day;

    in >> year;
    in.ignore(1);
    in >> month;
    in.ignore(1);
    in >> day;

    return {year, month, day};
  }

  static int ComputeDaysDiff(const Date& date_to, const Date& date_from) {
    const time_t timestamp_to = date_to.AsTimestamp();
    const time_t timestamp_from = date_from.AsTimestamp();
    return (timestamp_to - timestamp_from) / SECONDS_IN_DAY;
  }

  static Date Next(const Date& date) {
    const time_t next_day_ts = date.AsTimestamp() + SECONDS_IN_DAY;
    const tm* next_day = localtime(&next_day_ts);
    return {1900 + next_day->tm_year, 1 + next_day->tm_mon, next_day->tm_mday};
  }

  int Year() const { return year_; }
  int Month() const { return month_; }
  int Day() const { return day_; }

  bool operator==(const Date& other) const {
    return year_ == other.year_ && month_ == other.month_ && day_ == other.day_;
  }

  bool operator<(const Date& other) const {
    return ComputeDaysDiff(other, *this) > 0;
  }

  bool operator<=(const Date& other) const {
    return ComputeDaysDiff(other, *this) >= 0;
  }


  static const std::string delim;

 private:
  int day_;
  int month_;
  int year_;
};

const std::string Date::delim = "-";


std::ostream& operator<<(std::ostream& os, const Date& date) {
  return os << date.Year() << Date::delim << date.Month() << Date::delim
            << date.Day();
}

using IncomeValue = size_t;
using PureIncome = double;

class BudgetSystem {
  public:
  BudgetSystem() = default;

  PureIncome AccumulateIncome(const std::map<Date, PureIncome> &tr_report,
                                            const Date &from,
                                            const Date &to) const {
      PureIncome res{0};
      const auto begin_ = next(tr_report.upper_bound(from));
      const auto end_ = next(tr_report.upper_bound(Date::Next(to)));

      res += ComputeFromDateToBound(tr_report, from);
      res +=
          std::accumulate(begin_, end_, PureIncome{0},
                          [](PureIncome sum, auto p) { return sum + p.second; });
      res -= ComputeFromDateToBound(tr_report, Date::Next(to));

      return res;
  }

  PureIncome ComputeIncome(const Date& from, const Date& to) const {
    return AccumulateIncome(incomes_, from, to) -
           AccumulateIncome(spendings_, from, to);
  }

  void Earn(const Date& from, const Date& to, IncomeValue value) {
    return UpdateTransactions(Transaction::EARNING, from, to, value);
  }

  void Spend(const Date& from, const Date& to, IncomeValue value) {
    return UpdateTransactions(Transaction::SPENDING, from, to, value);
  }

  PureIncome ComputeIncomeAfterTax(PureIncome income,
                                                 size_t percent) {
    if (percent > 100) {
      throw std::out_of_range("Percent must be less or equal than 100");
    }

    return ((100 - percent) / double{100}) * income;
  }

  void PayTax(const Date& from, const Date& to, size_t percent) {
    auto before_tax = AddBoundDate(incomes_, from);
    auto last_payment = AddBoundDate(incomes_, Date::Next(to));

    auto tax_begin = next(before_tax);
    auto tax_end = next(last_payment);
    for (auto it = tax_begin; it != tax_end; ++it) {
      it->second = ComputeIncomeAfterTax(it->second, percent);
    }
  }

 private:
  using TransactionReport = std::map<Date, PureIncome>;
  TransactionReport incomes_ = {{Date{2000, 1, 1}, PureIncome{0}},
                                {Date{2100, 1, 1}, PureIncome{0}}};
  TransactionReport spendings_ = {{Date{2000, 1, 1}, PureIncome{0}},
                                  {Date{2100, 1, 1}, PureIncome{0}}};

  enum class Transaction {
    EARNING = 0,
    SPENDING,
  };
  const std::vector<TransactionReport*> transaction_reports = {&incomes_, &spendings_};

  void UpdateTransactions(Transaction tr, Date from, Date to, PureIncome value) {
    TransactionReport* tr_report = transaction_reports[static_cast<int>(tr)];

    auto begin_ = AddBoundDate(*tr_report, from);
    auto end_ = AddBoundDate(*tr_report, Date::Next(to));

    const int days = Date::ComputeDaysDiff(end_->first, begin_->first);
    for (auto it = std::next(begin_); it != std::next(end_); ++it) {
      int days_in_interval = Date::ComputeDaysDiff(it->first, from);
      it->second += (value * days_in_interval) / days;
      from = it->first;
    }
  }

  std::map<Date, PureIncome>::iterator AddBoundDate(
      std::map<Date, PureIncome>& transaction_history, const Date& date) {
    auto nearest = transaction_history.lower_bound(date);
    if (nearest->first == date) {
      return nearest;
    }

    auto previous = std::prev(nearest);

    int days_original = Date::ComputeDaysDiff(nearest->first, previous->first);
    int days_before = Date::ComputeDaysDiff(date, previous->first);

    PureIncome value = nearest->second * days_before / days_original;
    nearest->second -= value;

    return transaction_history.emplace(date, value).first;
  }

  PureIncome ComputeFromDateToBound(
      const std::map<Date, PureIncome>& transaction_history,
      const Date& date) const {
    auto nearest = transaction_history.lower_bound(date);
    if (nearest->first == date) {
      return std::next(nearest)->second;
    }

    auto previous = std::prev(nearest);

    int days_original = Date::ComputeDaysDiff(nearest->first, previous->first);
    int days_after = Date::ComputeDaysDiff(nearest->first, date);

    return nearest->second * days_after / days_original;
  }
};


enum class QueryType {
  COMPUTE_INCOME,
  EARN,
  SPEND,
  PAY_TAX,

  NOT_SUPPORTED
};

QueryType ParseQueryType(string_view query) {
  if (query == "Earn") {
    return QueryType::EARN;
  } else if (query == "Spend") {
    return QueryType::SPEND;
  } else if (query == "ComputeIncome") {
    return QueryType::COMPUTE_INCOME;
  } else if (query == "PayTax") {
    return QueryType::PAY_TAX;
  } else {
    return QueryType::NOT_SUPPORTED;
  }
}

int main() {
  cout.precision(25);

  BudgetSystem budget_system;

  size_t num_commands;
  cin >> num_commands;

  for (size_t i = 0; i < num_commands; ++i) {
    string query_type;
    cin >> query_type;

    string from_str;
    cin >> from_str;
    auto from = Date::FromString(from_str);

    string to_str;
    cin >> to_str;
    auto to = Date::FromString(to_str);

    switch (ParseQueryType(query_type)) {
      case QueryType::COMPUTE_INCOME:
        cout << budget_system.ComputeIncome(from, to) << endl;
        break;
      case QueryType::EARN:
        IncomeValue income_value;
        cin >> income_value;
        budget_system.Earn(from, to, income_value);
        break;
      case QueryType::SPEND:
        IncomeValue spend_value;
        cin >> spend_value;
        budget_system.Spend(from, to, spend_value);
        break;
      case QueryType::PAY_TAX:
        size_t percent;
        cin >> percent;
        budget_system.PayTax(from, to, percent);
        break;
      case QueryType::NOT_SUPPORTED:
        cout << "Operation is not supported" << endl;
        break;
    }
  }
}
