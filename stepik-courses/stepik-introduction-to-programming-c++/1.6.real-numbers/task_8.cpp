/*
Дан многочлен
P(x)= a_n*x^n + a_{n−1}*x^{n−1}+ ... + a_1*x + a_0 и число x.
Вычислите значение этого многочлена, воспользовавшись схемой Горнера:

P(x)=(...(((a_n*x + a_{n−1})x + a_{n−2})x + a_{n−3}) ... )x+ a_0

Формат входных данных

Сначала программе подается на вход целое неотрицательное число n ≤ 20,
затем действительное число x, затем следует n+1 вещественное число
— коэффициенты многочлена от старшего к младшему.
Формат выходных данных
Программа должна вывести значение многочлена.
Sample Input 1:

1
0.000
1.000
1.000
Sample Output 1:

1
Sample Input 2:

2
0.500
1.000
1.000
1.000
Sample Output 2:

1.75
 */

#include <iostream>
#include <iomanip>
#include <cmath>

// Попробую дописовать std::
int main() {
    // put your code here
    double n, x, n_plus_one, r = 0;
    std::cin >> n; // Неотрицательное число n ≤ 20
    std::cin >> x; // Действительное число x
    while (n >= 0) {
        std::cin >> n_plus_one;
        r = r * x + n_plus_one;
        n--;
    }
    std::cout << r;
    return 0;
}