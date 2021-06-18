#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double number, counter = 0, sum, sum_of_powers;
    cin >> number;
    sum = number;
    sum_of_powers = pow(number, 2.0);
    while (number != 0) {
        counter++;
        cin >> number;
        sum += number;
        sum_of_powers += pow(number, 2.0);
    }
    cout.precision(11);
    cout << sqrt((sum_of_powers - (pow(sum, 2.0) / counter)) / (counter - 1));

    return 0;
}
