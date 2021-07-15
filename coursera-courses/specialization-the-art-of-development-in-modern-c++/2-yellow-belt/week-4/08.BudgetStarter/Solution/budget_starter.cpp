#include <string>
#include <set>
#include <map>
#include <vector>
#include <tuple>
#include <iostream>
#include <sstream>

using namespace std;

//-------------------------------------------------------------------------------------------//
class Date {
    private:
        int Year;
        int Month;
        int Day;
    public:
        Date(int year = 0, int month = 0, int day = 0){
            Year = year;
            Month = month;
            Day = day;
        }

        Date(string& str, string delimiter){
            Year = stoi(str.substr(0, str.find(delimiter)));
            Month = stoi(str.substr(5, str.find(delimiter)));
            Day = stoi(str.substr(8, str.length() - 1));
        }

        int getYear() const {
            return Year;
        }

        int getMonth() const {
            return Month;
        }

        int getDay() const {
            return Day;
        }

        string getOutput() const {
            return to_string(Year) + "-" +
                ((Month) > 9 ? to_string(Month) : ("0" + to_string(Month)))  + "-"
                + ((Day) > 9 ? to_string(Day) : ("0" + to_string(Day)));
        }

        void plusDay() {
            if (Month == 12 and Day == 31) {
                Year += 1;
                Month = 1;
                Day = 1;
            }
            else if (Day == 31 and (Month == 1 or Month == 3 or Month == 5 or Month == 7 or Month == 8 or (Month == 10) or Month == 12)){
                Month += 1;
                Day = 1;
            } else if (Day == 30 and (Month == 4 or Month == 6 or Month == 9 or Month == 11)) {
                Month += 1;
                Day = 1;
            } else if (Month == 2 and Day == 28 and ((Year % 400 == 0) or (Year % 4 == 0 and Year % 100 != 0))) {
                Day += 1;
            } else if (Month == 2 and (Day == 28 or Day == 29)) {
                Month += 1;
                Day = 1;
            } else {
                Day += 1;
            }
        }
};


class Budget{
    public:
        map<string, double> getBudgetData() const {
            return budgetData;
        }

        double initBudget(string& fdate, string& sdate) {
            Date firstDate(fdate, "-");
            Date secondDate(sdate, "-");
            secondDate.plusDay();


            double zero = 0, counter = 0;

            do {
                if (budgetData.find(firstDate.getOutput()) == budgetData.end()){
                    budgetData[firstDate.getOutput()] = zero;
                }

                firstDate.plusDay();
                counter++;
            } while(firstDate.getOutput() != secondDate.getOutput());

            return counter;
        }

        void budgetAppend(string& fdate, string& sdate, double amount){
            Date firstDate(fdate, "-");
            Date secondDate(sdate, "-");
            secondDate.plusDay();

            double value = 0, dquan = 0;

            dquan = initBudget(fdate, sdate);
            value = amount / dquan;

            do {
                budgetData[firstDate.getOutput()] += value;
                firstDate.plusDay();

            } while(firstDate.getOutput() != secondDate.getOutput());
        }


        double budgetCount(string& fdate, string& sdate){
            Date firstDate(fdate, "-");
            Date secondDate(sdate, "-");
            secondDate.plusDay();

            double output = 0;

            do {
                output += budgetData[firstDate.getOutput()];
                firstDate.plusDay();
            } while(firstDate.getOutput() != secondDate.getOutput());

            return output;
        }

    private:
        map<string, double> budgetData;
};

//-------------------------------------------------------------------------------------------//
int main() {
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

