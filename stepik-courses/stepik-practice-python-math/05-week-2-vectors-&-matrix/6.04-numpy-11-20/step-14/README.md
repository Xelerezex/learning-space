## 20

Если у нас есть матрица (или numpy массив большей размерности), то её можно представить в линейном виде:

![alt tag](https://github.com/Xelerezex/learning-space/tree/learning-space/stepik-courses/stepik-practice-python-math/5-week-2-vectors-%26-matrix/6.4-numpy-11-20/step-14/Source/1.png)

Идея в том, что можно каждому элементу матрицы можно поставить в соответствие индекс.

Функция [numpy.unravel_index](https://docs.scipy.org/doc/numpy-1.15.0/reference/generated/numpy.unravel_index.html) проводит обратную операцию - по индексу элемента определяет его "координаты" в матрице.


Даны:

-   индекс i
-   numpy массив Z

Определите "координаты" элемента с индексом i в Z и выведите кортеж с координатами на печать.

***Примечание.*** В этой задаче не нужно ничего считывать. i и Z уже заполнены.

**Sample Input 1:**

```commandline
i = 5
array([[ 0,  1,  2,  3],
       [ 4,  5,  6,  7],
       [ 8,  9, 10, 11]])
```

**Sample Output 1:**

```commandline
(1, 1)
```

**Sample Input 2:**

```commandline
i = 3
array([ 10,  11,  12,  13,  14,  15])
```

**Sample Output 2:**

```commandline
(3,)
```

**Sample Input 3:**

```commandline
i = 4
array([[[ 1,  2],
        [ 3,  4]],

       [[11, 12],
        [13, 14]]])
```

**Sample Output 3:**

```commandline
(1, 0, 0)
```
