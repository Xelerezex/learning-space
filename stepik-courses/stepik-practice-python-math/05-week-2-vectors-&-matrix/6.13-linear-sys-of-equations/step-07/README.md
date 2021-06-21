## Задача 4 - система произвольного числа линейных уравнений

В этом задании необходимо объединить знания полученные в предыдущих задачах.

Напишите программу, которая будет решать систему линейных уравнений вида:

<img src="https://latex.codecogs.com/svg.image?\left\{\begin{matrix}&space;a_{11}x_{1}&plus;...&plus;&space;a_{1j}x_{i}=b_{1}&(1)&space;\\&space;a_{21}x_{1}&plus;...&plus;&space;a_{2j}x_{i}=b_{2}&(2)&space;\\&space;...&space;\\&space;a_{i1}x_{1}&plus;...&space;&plus;&space;a_{ij}x_{i}=b_{i}&(i)&space;\end{matrix}\right." title="\left\{\begin{matrix} a_{11}x_{1}+...+ a_{1j}x_{i}=b_{1}&(1) \\ a_{21}x_{1}+...+ a_{2j}x_{i}=b_{2}&(2) \\ ... \\ a_{i1}x_{1}+... + a_{ij}x_{i}=b_{i}&(i) \end{matrix}\right." />

На вход программа должна принимать в первой строке натуральное число i (i>1) и ещё i строк каждая строка содержит i+1 действительное число через пробел:

<img src="https://latex.codecogs.com/svg.image?a_{j1},&space;a_{j2},&space;a_{j3},&space;...&space;a_{ji},&space;b_{j}," title="a_{j1}, a_{j2}, a_{j3}, ... a_{ji}, b_{j}," />

где j - номер строки

На выходе программа должна выдавать:

-    значения <img src="https://latex.codecogs.com/svg.image?x_{1},&space;x_{2},&space;x_{3},&space;...&space;x_{i}" title="x_{1}, x_{2}, x_{3}, ... x_{i}" /> в одну строку через пробел, если система имеет решение

-    строку "Матрица системы вырожденная", если определитель матрицы равен 0.

**Важно!** Среди наборов данных для проверки могут быть системы длины больше 4!

_В следующем материале приведён алгоритм решения данной задачи. Постарайтесь решить её самостоятельно._

**Sample Input 1:**

```commandline
2
0 0 3
4 5 6
```

**Sample Output 1:**

```commandline
Матрица системы вырожденная
```

**Sample Input 2:**

```commandline
2
1 2 3
4 5 6
```

**Sample Output 2:**

```commandline
-1.0 2.0
```

**Sample Input 3:**

```commandline
3
3 2 -1 4
2 -1 5 23
1 7 -1 5
```

**Sample Output 3:**

```commandline
2.0 1.0000000000000002 3.9999999999999996
```

**Sample Input 4:**

```commandline
5
1 2 3 4 5 10
2 4 6 8 10 10
2 6 8 4 1 -10
-3 7 5 3 0 11
5 9 -4 1.5 0 9.999
```
