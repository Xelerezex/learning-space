## Энигма v0.2

Реализуйте функцию enigma(text, ref, rot1, shift1, rot2, shift2, rot3, shift3) с поворачивающимися роторами, как они описаны на предыдущем шаге.

-    text - исходный текст, который необходимо зашифровать
-    ref - номер отражателя (согласно задаче https://stepik.org/lesson/283487/step/3)
-    rot1, rot2, rot3 - номера роторов (согласно задаче https://stepik.org/lesson/283487/step/2)
-    shift1, shift2, shift3 - сдвиги роторов (1, 2 и 3, соответственно)

_Первые тестовые сценарии соответствуют примерам 3-6 с предыдущего шага_

P.S. _Не забудьте, что вам надо реализовать (или взять из предыдущего урока) функцию для шифрования Цезаря, использующуюся в сдвигах._

**Sample Input 1:**

```commandline
enigma('A', 1, 0, 0, 0, 0, 3, 2)
```

**Sample Output 1:**

```commandline
C
```

**Sample Input 2:**

```commandline
enigma('A', 1, 1, 0, 2, 0, 3, 2)
```

**Sample Output 2:**

```commandline
D
```

**Sample Input 3:**

```commandline
enigma('A', 1, 1, 0, 2, 1, 3, 1)
```

**Sample Output 3:**

```commandline
Y
```

**Sample Input 4:**

```commandline
enigma('A', 1, 1, 1, 2, 2, 3, 1)
```

**Sample Output 4:**

```commandline
Q
```

**Sample Input 5:**

```commandline
enigma('Some encripted text', 1, 1, 1, 2, 2, 3, 1)
```

**Sample Output 5:**

```commandline
TLXPPVFDYESPRSPMS
```

**Sample Input 6:**

```commandline
enigma('Some encripted text', 1, 1, -1, 2, 2, 3, -1)
```

**Sample Output 6:**

```commandline
AYIQQLXZMFHQUHQCH
```

**Sample Input 7:**

```commandline
enigma('AYIQQLXZMFHQUHQCH', 1, 1, -1, 2, 2, 3, -1)
```

**Sample Output 7:**

```commandline
SOMEENCRIPTEDTEXT
```
