## 10.1

Дан вектор Z

Запишите в переменную NonZerros индексы ненулевых элементов.

Используйте функцию https://docs.scipy.org/doc/numpy-1.15.0/reference/generated/numpy.nonzero.html

***Примечание.*** В этой задаче не нужно ничего считывать или выводить на печать. Матрица _Z_ уже готова, просто создайте _NonZerros_.

**Sample Input 1:**

```commandline
array([1, 0, 2, 0, 3, 0, 4])
```

**Sample Output 1:**

```commandline
(array([0, 2, 4, 6]),)
```

**Sample Input 2:**

```commandline
[1, 2, 0, 0, 4, 0]
```

**Sample Output 2:**

```commandline
(array([0, 1, 4]),)
```
