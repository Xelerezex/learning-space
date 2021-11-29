## Matrix Sum

В лекциях мы рассмотрели пример, в котором сначала выполнялась генерация квадратной матрицы, а затем находилась сумма
элементов в ней. При этом нам удалось ускорить генерацию матрицы за счёт применения многопоточности. В этой задаче вам
нужно сделать то же самое для суммирования элементов матрицы.

Вам нужно написать функцию ```int64_t CalculateMatrixSum(const vector<vector<int>>& matrix)```, которая получает на вход
квадратную матрицу и возвращает сумму элементов в ней.

Ваша реализация будет тестироваться следующим образом:

-   на вход вашей функции будут подаваться квадратные матрицы размером до *9000* (в данном случае размер матрицы — это
    количество строк в ней);

-   для одной и той же матрицы функция ```CalculateMatrixSum``` будет запускаться несколько раз; среднее время работы
    одного вызова в нашей тестирующей системе не должно превышать *15* мс;

> [matrix_sum.cpp](https://d3c33hcgiwev3.cloudfront.net/Wcm3P2gPEei5FgrpHNEYyg_5a36f770680f11e89aea310604ae9f7c_matrix_sum.cpp?Expires=1638316800&Signature=SyeA7HGNRUkLUS4jtwvYHFybltIOTuOj1fRBcsrBIy0eq2GDPVjOu-S~q0DZyyk-z-wmwilbMDfnkPANo4FWHt6WpdbT6CGushTA0g43zGwU774RmNZw0DP0wKo~tx1X4QnCmRq6E-nRbYT63xOhg8GyLkc8SvsQ~6duUi0w6Jg_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
