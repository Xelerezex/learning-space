## 4

Посчитайте размер матрицы Z в байтах и выведите его на печать.

Чтобы узнать размер (в байтах) 1 элемента матрицы используйте атрибут https://docs.scipy.org/doc/numpy-1.15.1/reference/generated/numpy.ndarray.itemsize.html

**Примечание.** _В этой задаче не нужно ничего считывать - матрица Z уже заполнена._

**Sample Input 1:**

```commandline
np.zeros((10,10))
```

**Sample Output 1:**

```commandline
800
```

**Sample Input 2:**

```commandline
np.array([1,2,3], dtype=np.float64)
```

**Sample Output 2:**

```commandline
24
```
