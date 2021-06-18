Напишите программу, которая считывает строку с числом nnn, которое задаёт количество чисел, которые нужно считать.

Далее считывает nnn строк с числами <img src="https://latex.codecogs.com/svg.image?x_{i}" title="x_{i}" />, по одному числу в каждой строке. Итого будет <img src="https://latex.codecogs.com/svg.image?n&space;&plus;&space;1" title="n + 1" /> строк.

При считывании числа <img src="https://latex.codecogs.com/svg.image?x_{i}" title="x_{i}" /> программа должна на отдельной строке вывести значение <img src="https://latex.codecogs.com/svg.image?f(x_{i})" title="f(x_{i})" />.

Функция ```f(x)``` уже реализована и доступна для вызова.

Функция вычисляется достаточно долго и зависит только от переданного аргумента <img src="https://latex.codecogs.com/svg.image?x" title="x" />.

Для того, чтобы уложиться в ограничение по времени, нужно избежать повторного вычисления значений.

**Sample Input:**

```commandline
5
5
12
9
20
12
```


**Sample Output:**

```commandline
11
41
47
61
41
```


