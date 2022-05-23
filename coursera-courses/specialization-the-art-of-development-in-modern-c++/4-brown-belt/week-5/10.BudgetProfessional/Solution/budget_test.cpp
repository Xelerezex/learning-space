#include "budget_test.h"

#include <algorithm>
#include <iterator>
#include <numeric>
#include <utility>
#include <vector>

#include "budget_system.h"
#include "date.h"
#include "test_runner.h"

using namespace std;

void TestDate::TestConstructor() {
  {
    // First supported date
    Date date{2000, 1, 1};
    ASSERT_EQUAL(date.year_, 2000);
    ASSERT_EQUAL(date.month_, 1);
    ASSERT_EQUAL(date.day_, 1);
  }

  {
    // Last supported date
    Date date{2100, 1, 1};
    ASSERT_EQUAL(date.year_, 2100);
    ASSERT_EQUAL(date.month_, 1);
    ASSERT_EQUAL(date.day_, 1);
  }

  {
    // Invalid date: negative numbers
    // ASSERT_THROWS(([] { return Date{-1, 1, 1}; }));
    // ASSERT_THROWS(([] { return Date{2000, -1, 1}; }));
    // ASSERT_THROWS(([] { return Date{2000, 1, -1}; }));
  }
}

void TestDate::TestValidate() {
  {
    // Supported range
    ASSERT(Date::Validate(2000, 1, 1));
    ASSERT(Date::Validate(2100, 1, 1));
  }

  {
    // Invalid date: negative numbers
    ASSERT(!Date::Validate(-1, 1, 1));
    ASSERT(!Date::Validate(2000, -1, 1));
    ASSERT(!Date::Validate(2000, 1, -1));
  }

  {
    // Test leap years from 2000 to 2099

    vector<int> supported_years(100);
    iota(begin(supported_years), end(supported_years), 2000);

    auto it = partition(begin(supported_years), end(supported_years),
                        [](int year) { return year % 4 == 0; });

    vector<int> leap_years(25);
    vector<int> non_leap_years(75);

    copy(begin(supported_years), it, begin(leap_years));
    copy(it, end(supported_years), begin(non_leap_years));

    for (int year : leap_years) {
      ASSERT(Date::Validate(year, 2, 29));
    }

    for (int year : non_leap_years) {
      ASSERT(!Date::Validate(year, 2, 29));
    }
  }
}

void TestDate::TestAsTimestamp() {}

void TestDate::TestFromString() {
  {
    Date expected{2000, 1, 1};
    Date actual = Date::FromString("2000-01-01");
    ASSERT_EQUAL(actual.year_, expected.year_);
    ASSERT_EQUAL(actual.month_, expected.month_);
    ASSERT_EQUAL(actual.day_, expected.day_);
  }
  {
    Date expected{2100, 1, 1};
    Date actual = Date::FromString("2100-01-01");
    ASSERT_EQUAL(actual.year_, expected.year_);
    ASSERT_EQUAL(actual.month_, expected.month_);
    ASSERT_EQUAL(actual.day_, expected.day_);
  }

  // ASSERT_THROWS(([] { return Date::FromString("20000101"); }));
  // ASSERT_THROWS(([] { return Date::FromString("200001-01"); }));
  // ASSERT_THROWS(([] { return Date::FromString("2000-0101"); }));
}

void TestDate::TestComputeDaysDiff() {
  ASSERT_EQUAL(Date::ComputeDaysDiff({2000, 1, 1}, {2000, 1, 1}), 0);
  ASSERT_EQUAL(Date::ComputeDaysDiff({2000, 1, 2}, {2000, 1, 1}), 1);
  ASSERT_EQUAL(Date::ComputeDaysDiff({2002, 1, 1}, {2001, 1, 1}), 365);
  ASSERT_EQUAL(Date::ComputeDaysDiff({2001, 1, 1}, {2000, 1, 1}), 366);
}

void TestDate::TestAll() {
  TestRunner tr;
  RUN_TEST(tr, TestConstructor);
  RUN_TEST(tr, TestValidate);
  RUN_TEST(tr, TestAsTimestamp);
  RUN_TEST(tr, TestFromString);
  RUN_TEST(tr, TestComputeDaysDiff);
}

void TestBudgetSystem::TestInsertNewIncome() {
  {
    BudgetSystem bs;

    bs.AddBoundDate(bs.incomes_, {2000, 1, 2});

    const map<Date, PureIncome> expected{
        {{2000, 1, 1}, 0}, {{2000, 1, 2}, 0}, {{2100, 1, 1}, 0}};

    ASSERT_EQUAL(bs.incomes_.size(), expected.size());
    for (const auto& [date, income] : bs.incomes_) {
      ASSERT(expected.count(date));
      ASSERT_EQUAL(income, expected.at(date));
    }
  }

  {
    BudgetSystem bs;

    bs.incomes_.emplace(Date{2000, 1, 11}, PureIncome{10});

    bs.AddBoundDate(bs.incomes_, {2000, 1, 6});

    const map<Date, PureIncome> expected{{{2000, 1, 1}, 0},
                                         {{2000, 1, 6}, 5},
                                         {{2000, 1, 11}, 5},
                                         {{2100, 1, 1}, 0}};

    ASSERT_EQUAL(bs.incomes_.size(), expected.size());
    for (const auto& [date, income] : bs.incomes_) {
      ASSERT(expected.count(date));
      ASSERT_EQUAL(income, expected.at(date));
    }
  }
}

void TestBudgetSystem::TestEarn() {
  {
    BudgetSystem bs;
    ASSERT_EQUAL(bs.incomes_.size(), 2u);
    ASSERT_EQUAL((bs.incomes_.begin()->first), (Date{2000, 1, 1}));
    ASSERT_EQUAL(bs.incomes_.begin()->second, PureIncome{0});
    ASSERT_EQUAL(std::next(bs.incomes_.begin())->first, (Date{2100, 1, 1}));
    ASSERT_EQUAL(std::next(bs.incomes_.begin())->second, PureIncome{0});
  }

  {
    BudgetSystem bs;
    const Date date{2000, 1, 1};
    const size_t value{1};
    bs.Earn(date, date, value);
    ASSERT_EQUAL(bs.incomes_.size(), 3u);

    ASSERT_EQUAL(bs.incomes_.at({2000, 1, 1}), 0);
    ASSERT_EQUAL(bs.incomes_.at({2000, 1, 2}), value);
    ASSERT_EQUAL(bs.incomes_.at({2100, 1, 1}), 0);
  }

  {
    BudgetSystem bs;

    const Date date_1{2000, 1, 1};
    const Date date_2{2000, 1, 2};
    const size_t value_1{1};
    const size_t value_2{2};

    bs.Earn(date_1, date_1, value_1);
    bs.Earn(date_1, date_2, value_2);

    const map<Date, PureIncome> expected{{{2000, 1, 1}, 0},
                                         {{2000, 1, 2}, 2},
                                         {{2000, 1, 3}, 1},
                                         {{2100, 1, 1}, 0}};

    ASSERT_EQUAL(bs.incomes_.size(), expected.size());
    for (const auto& [date, income] : bs.incomes_) {
      ASSERT(expected.count(date));
      ASSERT_EQUAL(income, expected.at(date));
    }
  }

  {
    BudgetSystem bs;

    bs.Earn({2000, 1, 1}, {2000, 1, 4}, 16);
    bs.Earn({2000, 1, 1}, {2000, 1, 2}, 8);

    const map<Date, PureIncome> expected{{{2000, 1, 1}, 0},
                                         {{2000, 1, 3}, 16},
                                         {{2000, 1, 5}, 8},
                                         {{2100, 1, 1}, 0}};

    ASSERT_EQUAL(bs.incomes_.size(), expected.size());
    for (const auto& [date, income] : bs.incomes_) {
      ASSERT(expected.count(date));
      ASSERT_EQUAL(income, expected.at(date));
    }
  }
}

void TestBudgetSystem::TestPayTax() {
  {
    BudgetSystem bs;
    ASSERT_EQUAL(bs.incomes_.size(), 2u);
    bs.PayTax({2000, 1, 1}, {2000, 1, 1});
    ASSERT_EQUAL(bs.incomes_.size(), 3u);
  }

  {
    BudgetSystem bs;
    const Date date{2000, 1, 1};
    bs.Earn(date, date, 100);
    bs.PayTax(date, date);

    const PureIncome expected{87};
    ASSERT_EQUAL(bs.incomes_.at({2000, 1, 1}), PureIncome{0});
    ASSERT_EQUAL(bs.incomes_.at({2000, 1, 2}), expected);
  }

  {
    BudgetSystem bs;

    bs.Earn({2000, 1, 1}, {2000, 1, 1}, 100);
    bs.PayTax({2000, 1, 1}, {2000, 1, 1});

    bs.Earn({2000, 1, 1}, {2000, 1, 2}, 1000);
    bs.PayTax({2000, 1, 1}, {2000, 1, 2});

    const PureIncome expected_1{510.69};
    ASSERT_EQUAL(bs.incomes_.at({2000, 1, 2}), expected_1);

    const PureIncome expected_2{435};
    ASSERT_EQUAL(bs.incomes_.at({2000, 1, 3}), expected_2);
  }

  {
    BudgetSystem bs;

    const Date date{2000, 1, 1};

    bs.Earn(date, date, 100);
    bs.PayTax(date, date, 0);

    ASSERT_EQUAL(bs.incomes_.at({2000, 1, 2}), 100);
  }

  {
    BudgetSystem bs;

    const Date date{2000, 1, 1};

    bs.Earn(date, date, 100);
    bs.PayTax(date, date, 1);

    ASSERT_EQUAL(bs.incomes_.at({2000, 1, 2}), 99);
  }

  {
    BudgetSystem bs;

    const Date date{2000, 1, 1};

    bs.Earn(date, date, 100);
    bs.PayTax(date, date, 30);

    ASSERT_EQUAL(bs.incomes_.at({2000, 1, 2}), 70);
  }

  {
    BudgetSystem bs;

    const Date date{2000, 1, 1};

    bs.Earn(date, date, 100);
    bs.PayTax(date, date, 50);
    bs.PayTax(date, date, 10);

    ASSERT_EQUAL(bs.incomes_.at({2000, 1, 2}), 45);
  }
}

void TestBudgetSystem::TestComputeIncome() {
  {
    BudgetSystem bs;

    bs.Earn({2000, 1, 1}, {2000, 1, 1}, 100);

    ASSERT_EQUAL(bs.ComputeIncome({2000, 1, 1}, {2000, 1, 1}), PureIncome{100});
  }

  {
    BudgetSystem bs;

    bs.Earn({2000, 1, 1}, {2000, 1, 1}, 100);
    bs.PayTax({2000, 1, 1}, {2000, 1, 1});
    const PureIncome income = bs.ComputeIncome({2000, 1, 1}, {2000, 1, 1});

    const PureIncome expected{87};
    ASSERT_EQUAL(income, expected);
  }

  {
    BudgetSystem bs;

    bs.Earn({2000, 1, 1}, {2000, 1, 1}, 100);
    bs.Earn({2000, 1, 1}, {2000, 1, 2}, 100);

    ASSERT_EQUAL(bs.ComputeIncome({2000, 1, 1}, {2000, 1, 1}), PureIncome{150});
  }

  {
    BudgetSystem bs;

    bs.Earn({2000, 1, 1}, {2000, 1, 1}, 100);
    bs.Earn({2000, 1, 1}, {2000, 1, 2}, 100);
    bs.PayTax({2000, 1, 1}, {2000, 1, 1});

    const PureIncome income = bs.ComputeIncome({2000, 1, 2}, {2000, 1, 2});

    const PureIncome expected{50};
    ASSERT_EQUAL(income, expected);
  }

  {
    BudgetSystem bs;

    bs.Earn({2000, 1, 1}, {2000, 1, 1}, 100);
    bs.PayTax({2000, 1, 1}, {2000, 1, 1});

    bs.Earn({2000, 1, 1}, {2000, 1, 2}, 100);
    bs.PayTax({2000, 1, 1}, {2000, 1, 2});

    const PureIncome income_1 = bs.ComputeIncome({2000, 1, 1}, {2000, 1, 1});
    const PureIncome expected_1{119.19};
    ASSERT_EQUAL(income_1, expected_1);

    const PureIncome income_2 = bs.ComputeIncome({2000, 1, 2}, {2000, 1, 2});
    const PureIncome expected_2{43.5};
    ASSERT_EQUAL(income_2, expected_2);
  }
}

void TestBudgetSystem::TestAll() {
  TestRunner tr;
  RUN_TEST(tr, TestInsertNewIncome);
  RUN_TEST(tr, TestEarn);
  RUN_TEST(tr, TestPayTax);
  RUN_TEST(tr, TestComputeIncome);
}
