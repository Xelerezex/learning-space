#include "tests.h"
#include "timer.h"
#include "budget_starter.h"

#include <exception>
#include <iostream>
#include <vector>


using namespace std;


int main() {

    TestAll();
    TimerAll();

    Budget BUDG;
    int quantity_commands;
    cin >> quantity_commands;


    for (int i = 0; i < quantity_commands; ++i) {

        string command;
        cin >> command;

        if (command == "Earn") {
            double amount;
            string fdate, sdate;
            cin >> fdate >> sdate >> amount;

            BUDG.budgetAppend(fdate, sdate, amount);


        } else if (command == "ComputeIncome") {
            string fdate, sdate;
            cin >> fdate >> sdate;

            cout.precision(25);
            cout << BUDG.budgetCount(fdate, sdate) << endl;
        }

    }
    return 0;
}
