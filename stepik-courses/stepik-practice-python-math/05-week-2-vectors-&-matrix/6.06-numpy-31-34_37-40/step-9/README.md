##  38

Переменная V содержит итерируемый объект.

Превратите его в одномерный numpy массив и сохраните в переменную Z. Массив будет содержать только числа типа float.

**Sample Input 1:**

```commandline
V = range(10)
```

**Sample Output 1:**

```commandline
[0. 1. 2. 3. 4. 5. 6. 7. 8. 9.]
```

**Sample Input 2:**

```commandline
V = map(numpy.sin, range(10))
```

**Sample Output 2:**

```commandline
[ 0.          0.84147098  0.90929743  0.14112001 -0.7568025  -0.95892427
 -0.2794155   0.6569866   0.98935825  0.41211849]
```

**Sample Input 3:**

```commandline
V = {1:2, 3:4}
```

**Sample Output 3:**

```commandline
[1. 3.]
```
