#ifndef BUDGET_H
#define BUDGET_H

#include <map>
#include <utility>
#include <vector>

#include "date.h"

#ifdef BUDGET_TEST
#include "budget_test.h"
#endif

using IncomeValue = size_t;
using PureIncome = double;

class BudgetSystem
{
    public:
        BudgetSystem() = default;

        PureIncome AccumulateIncome(const std::map<Date, PureIncome> &tr_report,
                                    const Date &from,
                                    const Date &to) const;
        PureIncome ComputeIncome(const Date& from, const Date& to) const;
        void Earn(const Date& from, const Date& to, IncomeValue value);
        void Spend(const Date& from, const Date& to, IncomeValue value);
        void PayTax(const Date& from, const Date& to, size_t percent = 13);

        static PureIncome ComputeIncomeAfterTax(PureIncome income,
                                                size_t percent = 13);

        #ifdef BUDGET_TEST
                friend class TestBudgetSystem;
        #endif
    private:
        using TransactionReport = std::map<Date, PureIncome>;
        TransactionReport incomes_ = {{Date{2000, 1, 1}, PureIncome{0}},
                                     {Date{2100, 1, 1}, PureIncome{0}}};
        TransactionReport spendings_ = {{Date{2000, 1, 1}, PureIncome{0}},
                                       {Date{2100, 1, 1}, PureIncome{0}}};

        enum class Transaction
        {
                EARNING = 0,
                SPENDING,
        };
        const std::vector<TransactionReport*> transaction_reports =
        {&incomes_, &spendings_};

        void UpdateTransactions(Transaction tr, Date from, Date to, PureIncome value);

        std::map<Date, PureIncome>::iterator AddBoundDate(
                        std::map<Date, PureIncome>& transaction_history, const Date& date);

        PureIncome ComputeFromDateToBound(
                        const std::map<Date, PureIncome>& transaction_history,
                        const Date& date) const;
};

#endif        // BUDGET_H
