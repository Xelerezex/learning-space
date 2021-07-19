#include "tests.h"
#include "timer.h"
#include "budget_starter_plus.h"


static const Date START_DATE = Date::FromString("1700-01-01");
static const Date END_DATE = Date::FromString("2099-12-31");
static const size_t DAY_COUNT = ComputeDaysDiff(END_DATE, START_DATE);

int main() {
    TestAll();
    TimerAll();

    vector<uint64_t> money(DAY_COUNT, 0);
    vector<uint64_t> partial_sums(DAY_COUNT, 0);
    size_t num_earnings;
    cin >> num_earnings;

    for (size_t i = 0; i < num_earnings; ++i) {
        uint64_t earning;
        string date;
        cin >> date >> earning;
        Date earn_date = Date::FromString(date);
        auto indx = ComputeDaysDiff(earn_date, START_DATE);
        money[indx] = earning;
    }

    partial_sum(money.begin(), money.end(), partial_sums.begin());

    size_t num_queries;
    cin >> num_queries;

    for (size_t i = 0; i < num_queries; ++i) {
        string date_from, date_to;
        cin >> date_from >> date_to;

        Date from = Date::FromString(date_from);
        Date to = Date::FromString(date_to);

        auto start_indx = ComputeDaysDiff(from, START_DATE);
        auto finish_indx = ComputeDaysDiff(to, START_DATE);

        if (start_indx > 0) {
            cout << partial_sums[finish_indx] - partial_sums[start_indx - 1] << '\n';
        } else {
            cout << partial_sums[finish_indx] << '\n';
        }
    }

    return 0;
}
