На вход подаётся 2 набора целых чисел.

Создайте вектор V такой, что он будет содержать числа из 1 набора, делящиеся нацело на предпоследнее число из 2 набора и разделённые на это число.

Если таких чисел не найдётся, то вектор V будет пустым (т.е. не будет содержать элементов).

***Примечание.*** В этой задаче не нужно ничего выводить на печать. Только создать вектора.

**Sample Input 1:**

```commandline
1, 2, 3, 4, 5, 6
1, 2, 3, 4
```

**Sample Output 1:**

```commandline
V[<class 'numpy.ndarray'>]: [1. 2.]
```

**Sample Input 2:**

```commandline
1, 2
10, 10
```

**Sample Output 2:**

```commandline
V[<class 'numpy.ndarray'>]: []
```