## 3.2

Считайте строку, где значения заданы через пробел shape и dtype

Последнее значение в строке может быть либо числом (тогда это последнее значение кортежа shape, либо строкой dtype)

-    shape - атрибут, задающий размеры матрицы нолей (позволяет вернуть вектор-строку, вектор-столбец, матрицу, куб и т.д.)
-    dtype - тип данных, использующихся для значений матрицы. По-умолчанию используется numpy.float64.

Создайте матрицу Z размера shape, со значениями типа dtype (если dtype не указан, используйте numpy.float64)

**Примечание.** В этой задаче не нужно ничего выводить на печать. Только создать матрицу Z.

**Sample Input 1:**

```commandline
5
```

**Sample Output 1:**

```commandline
[0. 0. 0. 0. 0.]
```

**Sample Input 2:**

```commandline
2 3 bool
```

**Sample Output 2:**

```commandline
[[False False False]
 [False False False]]
```

**Sample Input 3:**

```commandline
4 int
```

**Sample Output 3:**

```commandline
[0 0 0 0]
```
