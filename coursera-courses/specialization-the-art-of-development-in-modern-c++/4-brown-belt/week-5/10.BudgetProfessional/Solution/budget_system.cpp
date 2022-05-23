#include "budget_system.h"

#include <cstddef>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ostream>
#include <stdexcept>

#include "date.h"

PureIncome BudgetSystem::AccumulateIncome(const std::map<Date, PureIncome> &tr_report,
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

PureIncome BudgetSystem::ComputeIncome(const Date& from, const Date& to) const {
  return AccumulateIncome(incomes_, from, to) -
         AccumulateIncome(spendings_, from, to);
}

PureIncome BudgetSystem::ComputeFromDateToBound(
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

std::map<Date, PureIncome>::iterator BudgetSystem::AddBoundDate(
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

void BudgetSystem::Earn(const Date& from, const Date& to, IncomeValue value) {
  return UpdateTransactions(Transaction::EARNING, from, to, value);
}

void BudgetSystem::Spend(const Date& from, const Date& to, IncomeValue value) {
  return UpdateTransactions(Transaction::SPENDING, from, to, value);
}

void BudgetSystem::UpdateTransactions(Transaction tr, Date from, Date to, PureIncome value) {
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

PureIncome BudgetSystem::ComputeIncomeAfterTax(PureIncome income,
                                               size_t percent) {
  if (percent > 100) {
    throw std::out_of_range("Percent must be less or equal than 100");
  }

  return ((100 - percent) / double{100}) * income;
}

void BudgetSystem::PayTax(const Date& from, const Date& to, size_t percent) {
  auto before_tax = AddBoundDate(incomes_, from);
  auto last_payment = AddBoundDate(incomes_, Date::Next(to));

  auto tax_begin = next(before_tax);
  auto tax_end = next(last_payment);
  for (auto it = tax_begin; it != tax_end; ++it) {
    it->second = ComputeIncomeAfterTax(it->second, percent);
  }
}
