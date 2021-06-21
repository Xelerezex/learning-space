Задача 3 - система 4 линейных уравнений

Напишите программу, которая будет решать систему линейных уравнений вида:

<img src="https://latex.codecogs.com/svg.image?\left\{\begin{matrix}&space;a_{11}x_{1}&plus;a_{12}x_{2}&plus;a_{13}x_{3}&space;&plus;&space;a_{14}x_{4}=b_{1}&(1)&space;\\&space;a_{21}x_{1}&plus;a_{22}x_{2}&plus;a_{23}x_{3}&space;&plus;&space;a_{24}x_{4}=b_{2}&(2)&space;\\&space;a_{31}x_{1}&plus;a_{32}x_{2}&plus;a_{33}x_{3}&space;&plus;&space;a_{34}x_{4}=b_{3}&(3)&space;\\&space;a_{41}x_{1}&plus;a_{42}x_{2}&plus;a_{43}x_{3}&space;&plus;&space;a_{44}x_{4}=b_{4}&(4)&space;\end{matrix}\right." title="\left\{\begin{matrix} a_{11}x_{1}+a_{12}x_{2}+a_{13}x_{3} + a_{14}x_{4}=b_{1}&(1) \\ a_{21}x_{1}+a_{22}x_{2}+a_{23}x_{3} + a_{24}x_{4}=b_{2}&(2) \\ a_{31}x_{1}+a_{32}x_{2}+a_{33}x_{3} + a_{34}x_{4}=b_{3}&(3) \\ a_{41}x_{1}+a_{42}x_{2}+a_{43}x_{3} + a_{44}x_{4}=b_{4}&(4) \end{matrix}\right." />

На вход программа должна принимать 4 строки, каждая строка содержит 5 действительных числа через пробел:

<img src="https://latex.codecogs.com/svg.image?a_{i1},&space;a_{i2},&space;a_{i3},&space;a_{i4},&space;b_{i}," title="a_{i1}, a_{i2}, a_{i3}, a_{i4}, b_{i}," />

где i - номер строки

На выходе программа должна выдавать:

-   значения <img src="https://latex.codecogs.com/svg.image?x_{1},&space;x_{2},&space;x_{3},&space;x_{4}" title="x_{1}, x_{2}, x_{3}, x_{4}" /> в одну строку через пробел, если система имеет решение

-   строку "Матрица системы вырожденная", если определитель матрицы равен 0.

**Sample Input 1:**

```commandline
0 0 0 0 1
2 6 2 -5 0
1 6 1 5 -6
34 0 -5 1 6
```

**Sample Output 1:**

```commandline
Матрица системы вырожденная
```

**Sample Input 2:**

```commandline
1 0 1 0 2
-1 1 -2 1 -2
4 0 1 -2 0
-4 4 0 1 5
```

**Sample Output 2:**

```commandline
0.0 1.0 2.0 1.0
```
