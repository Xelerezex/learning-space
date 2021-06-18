Считайте 2 числа: n, m.

Зафиксируйте значение генератора случайных чисел Numpy с помощью

```commandline
numpy.random.seed(42)
```

Создайте матрицу n*m из случайных чисел (от 0 до 1).
Найдите среднее значение для каждого из столбцов.
Выведите на печать значение минимального и максимального среднего по столбцам (каждое с новой строки).

**ПРИМЕР**

![alt tag](https://github.com/Xelerezex/learning-space/tree/learning-space/stepik-courses/stepik-practice-python-math/5-week-2-vectors-%26-matrix/6.4-numpy-11-20/step-07/Source/1.png)

**0.15, 0.55 и 0.88 - средние значения по столбцам.**
**0.15 - минимальное среднее**
**0.88 - максимальное среднее**

Используйте атрибут axis функции https://docs.scipy.org/doc/numpy-1.13.0/reference/generated/numpy.mean.html

**Sample Input 1:**

```commandline
3 4
```

**Sample Output 1:**

```commandline
0.270220682758469
0.8115814940446553
```

**Sample Input 2:**

```commandline
12 6
```

**Sample Output 2:**

```commandline
0.3978200241403143
0.5425150112777877
```
