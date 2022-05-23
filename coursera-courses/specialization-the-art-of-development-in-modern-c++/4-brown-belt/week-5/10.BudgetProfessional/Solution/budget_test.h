#ifndef BUDGET_TEST_H
#define BUDGET_TEST_H

class TestDate {
 public:
  static void TestAll();

  static void TestConstructor();
  static void TestValidate();
  static void TestAsTimestamp();
  static void TestFromString();
  static void TestComputeDaysDiff();
};

class TestBudgetSystem {
 public:
  static void TestAll();

  static void TestInsertNewIncome();
  static void TestComputeIncome();
  static void TestEarn();
  static void TestPayTax();
};

#endif  // BUDGET_TEST_H
