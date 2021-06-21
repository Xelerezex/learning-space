## Задача 2 - система 3 линейных уравнений

Напишите программу, которая будет решать систему линейных уравнений вида:

<img src="https://latex.codecogs.com/svg.image?\left\{\begin{matrix}&space;a_{11}x&plus;a_{12}y&plus;a_{13}z=b_{1}&(1)&space;\\&space;a_{21}x&plus;a_{22}y&plus;a_{23}z=b_{2}&space;&(2)&space;\\&space;a_{31}x&plus;a_{32}y&plus;a_{33}z=b_{3}&space;&(3)&space;\end{matrix}\right." title="\left\{\begin{matrix} a_{11}x+a_{12}y+a_{13}z=b_{1}&(1) \\ a_{21}x+a_{22}y+a_{23}z=b_{2} &(2) \\ a_{31}x+a_{32}y+a_{33}z=b_{3} &(3) \end{matrix}\right." />

Для решения системы по аналогии с предыдущими задачами можно записать матрицу и вектор:

<img src="https://latex.codecogs.com/svg.image?M&space;=&space;\begin{pmatrix}&space;a_{11}&space;&&space;a_{12}&space;&&space;a_{13}\\&space;a_{21}&space;&&space;a_{22}&space;&&space;a_{23}\\&space;a_{31}&space;&&space;a_{32}&space;&&space;a_{33}&space;\end{pmatrix}&space;v&space;=&space;\begin{pmatrix}&space;b_{1}\\b_{2}&space;\\&space;b_{3}&space;\end{pmatrix}" title="M = \begin{pmatrix} a_{11} & a_{12} & a_{13}\\ a_{21} & a_{22} & a_{23}\\ a_{31} & a_{32} & a_{33} \end{pmatrix} v = \begin{pmatrix} b_{1}\\b_{2} \\ b_{3} \end{pmatrix}" />

При решении системы сделайте проверку на наличие решений.

На вход программа должна принимать 3 строки, каждая строка содержит 4 действительных числа через пробел:

<img src="https://latex.codecogs.com/svg.image?a_{i2},&space;a_{i3},&space;b_{i}," title="a_{i2}, a_{i3}, b_{i}," />

где i - номер строки


На выходе программа должна выдавать:

-    значения x, y и z в одну строку через пробел, если система имеет решение

-    строку "Матрица системы вырожденная", если определитель матрицы равен 0.

**Sample Input 1:**

```commandline
3 2 -1 4
2 -1 5 23
1 7 -1 5
```

**Sample Output 1:**

```commandline
2.0 1.0000000000000002 3.9999999999999996
```

**Sample Input 2:**

```commandline
1 3 1 5
2 6 2 0
1 6 1 5
```

**Sample Output 2:**

```commandline
Матрица системы вырожденная
```
