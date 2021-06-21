## Задача 5 - Найти коэффициенты многочлена

Напишите программу, находящую коэффициенты многочлена n-й степени, проходящего через n+1 точку:

<img src="https://latex.codecogs.com/svg.image?c_{0}&plus;c_{1}x^{1}&plus;c_{2}x^{2}&plus;\dots&space;&plus;c_{n}x^{n}" title="c_{0}+c_{1}x^{1}+c_{2}x^{2}+\dots +c_{n}x^{n}" />

Программа должна принимать на вход в 1й строке натуральное число M (M=n+1) после этого в цикле M строк. Каждая из M строк содержит 2 действительных числа: <img src="https://latex.codecogs.com/svg.image?x_{i},&space;y_{i}" title="x_{i}, y_{i}" /> - координаты M точек, через которые проходит график многочлена.

На выходе программа должна выдавать через пробел n+1 (n+1=M) коэффициент многочлена:

<img src="https://latex.codecogs.com/svg.image?c_{0},&space;c_{1},&space;c_{2}&space;\dots&space;c_{n}" title="c_{0}, c_{1}, c_{2} \dots c_{n}" />

```
Подсказка. Для этого необходимо решить систему n+1 линейных уравнений:
```

<img src="https://latex.codecogs.com/svg.image?\left\{\begin{matrix}&space;f(x_{1})&space;=&space;c_{0}&plus;c_{1}x_{1}^{1}&space;&plus;c_{2}x_{1}^{2}&space;&plus;&space;....&space;&plus;c_{n}x_{1}^{n}&space;\\&space;f(x_{2})&space;=&space;c_{0}&plus;c_{1}x_{2}^{1}&space;&plus;c_{2}x_{2}^{2}&space;&plus;&space;....&space;&plus;c_{n}x_{2}^{n}&space;\\&space;...&space;\\&space;f(x_{n})&space;=&space;c_{0}&plus;c_{1}x_{n}^{1}&space;&plus;c_{2}x_{n}^{2}&space;&plus;&space;....&space;&plus;c_{n}x_{n}^{n}&space;\\&space;f(x_{n&plus;1})&space;=&space;c_{0}&plus;c_{1}x_{n&plus;1}^{1}&space;&plus;c_{2}x_{n&plus;1}^{2}&space;&plus;&space;....&space;&plus;c_{n}x_{n&plus;1}^{n}&space;\end{matrix}\right." title="\left\{\begin{matrix} f(x_{1}) = c_{0}+c_{1}x_{1}^{1} +c_{2}x_{1}^{2} + .... +c_{n}x_{1}^{n} \\ f(x_{2}) = c_{0}+c_{1}x_{2}^{1} +c_{2}x_{2}^{2} + .... +c_{n}x_{2}^{n} \\ ... \\ f(x_{n}) = c_{0}+c_{1}x_{n}^{1} +c_{2}x_{n}^{2} + .... +c_{n}x_{n}^{n} \\ f(x_{n+1}) = c_{0}+c_{1}x_{n+1}^{1} +c_{2}x_{n+1}^{2} + .... +c_{n}x_{n+1}^{n} \end{matrix}\right." />

**Sample Input 1:**

```commandline
2
0 2
2 0
```

**Sample Output 1:**

```commandline
2.0 -1.0
```

**Sample Input 2:**

```commandline
3
-2 0
2 0
0 -4
```

**Sample Output 2:**

```commandline
-4.0 0.0 1.0
```
