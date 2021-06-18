## 16

Имеется матрица Z

Добавьте вокруг имеющихся значений матрицы "забор" из 0.

![alt tag](https://github.com/Xelerezex/learning-space/tree/learning-space/stepik-courses/stepik-practice-python-math/5-week-2-vectors-%26-matrix/6.4-numpy-11-20/step-09/Source/1.png)

Результат должен быть сохранён в ту же переменную Z.

Попробуйте использовать функцию https://docs.scipy.org/doc/numpy-1.15.1/reference/generated/numpy.pad.html

***Примечание.*** _В этой задаче не нужно ничего считывать или выводить на печать. Только модифицировать матрицу Z._

**Sample Input:**

```commandline
array([[1, 2, 3],
       [4, 5, 6],
       [7, 8, 9]])
```

**Sample Output:**

```commandline
[[0 0 0 0 0]
 [0 1 2 3 0]
 [0 4 5 6 0]
 [0 7 8 9 0]
 [0 0 0 0 0]]
```
