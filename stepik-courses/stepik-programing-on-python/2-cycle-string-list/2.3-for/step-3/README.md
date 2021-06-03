Когда Павел учился в школе, он запоминал таблицу умножения прямоугольными блоками. Для тренировок ему бы очень пригодилась программа, которая показывала бы блок таблицы умножения.

Напишите программу, на вход которой даются четыре числа <img src="https://latex.codecogs.com/svg.image?a,&space;b,&space;c,&space;d" title="a, b, c, d" /> каждое в своей строке. Программа должна вывести фрагмент таблицы умножения для всех чисел отрезка [a; b] на все числа отрезка [c; d].

Числа <img src="https://latex.codecogs.com/svg.image?a,&space;b,&space;c,&space;d" title="a, b, c, d" /> являются натуральными и не превосходят 10, <img src="https://latex.codecogs.com/svg.image?a&space;\leq&space;&space;b,&space;c&space;\leq&space;&space;d" title="a \leq b, c \leq d" /> .

Следуйте формату вывода из примера, для разделения элементов внутри строки используйте '\t' — символ табуляции. Заметьте, что левым столбцом и верхней строкой выводятся ***сами числа из заданных отрезков*** — заголовочные столбец и строка таблицы.

**Sample Input 1:**

```commandline
7
10
5
6
```


**Sample Output 1:**

```commandline
    5   6
7   35  42
8   40  48
9   45  54
10  50  60
```


**Sample Input 2:**

```commandline
5
5
6
6
```


**Sample Output 2:**

```commandline
    6
5   30
```


**Sample Input 3:**

```commandline
1
3
2
4
```


**Sample Output 3:**

```commandline
    2   3   4
1   2   3   4
2   4   6   8
3   6   9   12
```


