## Энигма v0.3

Реализуйте функцию enigma(text, ref, rot1, shift1, rot2, shift2, rot3, shift3) с поворачивающимися и двигающимися роторами, как они описаны на предыдущем шаге.

-    text - исходный текст, который необходимо зашифровать
-    ref - номер отражателя (согласно задаче https://stepik.org/lesson/283487/step/3)
-    rot1, rot2, rot3 - номера роторов (согласно задаче https://stepik.org/lesson/283487/step/2)
-    shift1, shift2, shift3 - сдвиги роторов (1, 2 и 3, соответственно)

Не забывайте, что правый ротор смещается на 1 ДО того как начнёт кодироватсья каждый новый символ. А так же, что в определённых ситуациях Роторы сдвигают соседей слева от себя.

**Sample Input 1:**

```commandline
enigma('AAAAAAA', 1, 1, 0, 2, 0, 3, 0)
```

**Sample Output 1:**

```commandline
BDZGOWC
```

**Sample Input 2:**

```commandline
enigma('BDZGOWC', 1, 1, 0, 2, 0, 3, 0)
```

**Sample Output 2:**

```commandline
AAAAAAA
```

**Sample Input 3:**

```commandline
enigma('AAAAAAA', 1, 2, 3, 2, 3, 2, 3)
```

**Sample Output 3:**

```commandline
BGDMBTZ
```

**Sample Input 4:**

```commandline
enigma('AAAAA AAAAA AAAAA AAAAA AAAAA AAAAA AAAAA AAAAA AAAAA AAAAA AAAAA', 1, 2, 3, 2, 3, 2, 3)
```

**Sample Output 4:**

```commandline
BGDMBTZUONCIZMORCPNVLGOVLMURTNZNDROPETXLPLYCMIBICXITUCM
```

**Sample Input 5:**

```commandline
enigma('AAAAA AAAAA', 1, 1, 0, 2, 0, 2, 0)
```

**Sample Output 5:**

```commandline
SMGJHIUWUF
```

**Sample Input 6:**

```commandline
enigma('AAAAA AAAAA', 1, 1, 0, 2, 0, 1, 0)
```

**Sample Output 6:**

```commandline
ZEMUOFUVNB
```
