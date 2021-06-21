## Задача 1.2 - система 2 линейных уравнений

Напишите программу, которая будет решать систему линейных уравнений вида:

<img src="https://latex.codecogs.com/svg.image?\left\{\begin{matrix}&space;a_{11}x&plus;a_{12}y=b_{1}&(1)&space;\\&space;a_{21}x&plus;a_{22}y=b_{2}&space;&(2)&space;\end{matrix}\right." title="\left\{\begin{matrix} a_{11}x+a_{12}y=b_{1}&(1) \\ a_{21}x+a_{22}y=b_{2} &(2) \end{matrix}\right." />

В отличие от задачи 1.1 здесь есть системы, не имеющие решений, например:

<img src="https://latex.codecogs.com/svg.image?\left\{\begin{matrix}&space;x&plus;y=1&(3)&space;\\&space;2x&plus;2y=5&space;&(4)&space;\end{matrix}\right." title="\left\{\begin{matrix} x+y=1&(3) \\ 2x+2y=5 &(4) \end{matrix}\right." />

Как мы знаем из лекций, система не имеет решения (или имеет их бесконечно много), если определитель матрицы коэффициентов равен 0:

<img src="https://latex.codecogs.com/svg.image?\Delta&space;=&space;\begin{pmatrix}&space;1&space;&&space;1&space;\\&space;2&space;&&space;2&space;\end{pmatrix}&space;=&space;0" title="\Delta = \begin{pmatrix} 1 & 1 \\ 2 & 2 \end{pmatrix} = 0" />

Для нахождения определителя используйте функцию numpy.linalg.det.

На вход программа должна принимать 2 строки, каждая строка содержит 3 действительных числа через пробел:

<img src="https://latex.codecogs.com/svg.image?a_{i1},&space;a_{i2},&space;b_{i}," title="a_{i1}, a_{i2}, b_{i}," />

где i - номер строки

На выходе программа должна выдавать:


-    значения x и y в одну строку через пробел, если система имеет решение

-    строку "Матрица системы вырожденная", если определитель матрицы равен 0.

**Sample Input 1:**

```commandline
2 5 1
1 -10 3
```

**Sample Output 1:**

```commandline
1.0 -0.2
```

**Sample Input 2:**

```commandline
1 1 1
2 2 5
```

**Sample Output 2:**

```commandline
Матрица системы вырожденная
```
