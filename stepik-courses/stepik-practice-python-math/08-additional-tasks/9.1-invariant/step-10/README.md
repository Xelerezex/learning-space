## Задача 4.3 - пятнашки (на поле произвольного размера)

Пример таких "пятнашек" размера 4х6 из советского прошлого:

![alt tag](https://github.com/Xelerezex/learning-space/blob/learning-space/stepik-courses/stepik-practice-python-math/08-additional-tasks/9.1-invariant/step-10/Source/1.jpg)

Не сложно догадаться, что тот же принцип определения чётности перестановки лежит в основе определения возможности "выиграть", находясь в любой стартовой позиции "пятнашек" на произвольном поле размера NхM, где N и M не меньше 2.

Реализуйте алгоритм, который:

1.    принимает на вход 2 числа, разделённых пробелом (n m)

2.    принимает на вход n строк с числами, разделёнными пробелом (в n-1 строке будет m чисел, а в последней строке будет m-1 число)

3.    Считая, что числа записаны "змейкой" (аналогично задаче 3.2), определить может ли данная игровая ситуация быть приведена к "выигрышной". Для этого определяем чётность перестановки "эталонной" позиции и сравниваем с чётностью перестановки текущей позиции.

- Если чётности равны, вывести "Бинго!"

- Если чётности отличаются, вывести "Не повезло..."

***Примечание.***

Эталонная комбинация для поля <img src="https://latex.codecogs.com/svg.image?N&space;\times&space;M" title="N \times M" /> содержит <img src="https://latex.codecogs.com/svg.image?N&space;*&space;M&space;-&space;1" title="N * M - 1" /> чисел по порядку от 1 до <img src="https://latex.codecogs.com/svg.image?N&space;*&space;M&space;-&space;1" title="N * M - 1" /> (т.к. последняя ячейка остаётся пустой).

![alt tag](https://github.com/Xelerezex/learning-space/blob/learning-space/stepik-courses/stepik-practice-python-math/08-additional-tasks/9.1-invariant/step-10/Source/2.jpg)

При этом

-    первые n-1 строк содержат по m чисел
-    последняя строка содержит m-1 число

_Подумайте как можно записать ряд чисел в i-й строке._

**Sample Input 1:**

```commandline
2 2
1 2
3
```

**Sample Output 1:**

```commandline
Бинго!
```

**Sample Input 2:**

```commandline
2 2
1 3
2
```

**Sample Output 2:**

```commandline
Не повезло...
```

**Sample Input 3:**

```commandline
3 3
1 2 3
6 5 4
7 8
```

**Sample Output 3:**

```commandline
Бинго!
```

**Sample Input 4:**

```commandline
3 3
1 2 3
6 5 4
8 7
```

**Sample Output 4:**

```commandline
Не повезло...
```

**Sample Input 5:**

```commandline
4 4
1 2 3 4
8 7 6 5
9 10 11 12
15 13 14
```

**Sample Output 5:**

```commandline
Не повезло...
```

**Sample Input 6:**

```commandline
5 8
1 2 3 4 5 6 7 8
16 15 14 13 12 11 10 9
17 18 19 20 21 22 23 24
32 31 30 29 28 27 26 25
33 34 35 36 37 38 39
```

**Sample Output 6:

```commandline
Бинго!
```
