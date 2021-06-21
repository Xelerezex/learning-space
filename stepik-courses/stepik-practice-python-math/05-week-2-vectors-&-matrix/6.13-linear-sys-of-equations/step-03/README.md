## Задача 1.1 - система 2 линейных уравнений

Напишите программу, которая будет решать систему линейных уравнений вида:

<img src="https://latex.codecogs.com/svg.image?\left\{\begin{matrix}&space;a_{11}x&plus;a_{12}y=b_{1}&(1)&space;\\&space;a_{21}x&plus;a_{22}y=b_{2}&space;&(2)&space;\end{matrix}\right." title="\left\{\begin{matrix} a_{11}x+a_{12}y=b_{1}&(1) \\ a_{21}x+a_{22}y=b_{2} &(2) \end{matrix}\right." />

На вход программа должна принимать 2 строки (используйте стандартную функцию input() Python 3).

Каждая строка содержит 3 действительных числа через пробел:

<img src="https://latex.codecogs.com/svg.image?a_{i1},&space;a_{i2},&space;b_{i}," title="a_{i1}, a_{i2}, b_{i}," />

где i - номер строки

На выходе программа должна выдавать значения x и y в одну строку через пробел.


**Примечание 1.** _Для разделения строки на отдельные элементы используйте функцию split()_

**Примечание 2.** _В качестве разделителя между целой и дробной частью используйте точку, например 0.2_

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
1 0 1
0 1 -1
```

**Sample Output 2:**

```commandline
1.0 -1.0
```
