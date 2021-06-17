## B. front_back

Рассмотрим разделение строки на две половины.

-    Если длина четная, 1я и 2я части имеют одинаковую длину
-    Если длина нечетная, мы скажем, что дополнительный символ идет в передней половине

например, «abcde»: 1я часть - «abc», 2я часть «de».

Напишите функцию front_back(a, b), принимающую 2 строки, a и b, и возвращающую строку формы

```commandline
# a-front + b-front + a-back + b-back
```

***Примечание.*** В этой задаче не нужно ничего считывать и ничего выводить на печать. Только реализовать функцию.

**Sample Input 1:**

```commandline
abcd
xy
```

**Sample Output 1:**

```commandline
abxcdy
```

**Sample Input 2:**

```commandline
abcde
xyz
```

**Sample Output 2:**

```commandline
abcxydez
```

**Sample Input 3:**

```commandline
Kitten
Donut
```

**Sample Output 3:**

```commandline
KitDontenut
```

