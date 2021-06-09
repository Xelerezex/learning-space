Логично продолжить наши упражнения, создав свой алфавит. Для начала создадим алфавит, отличающийся от исходного только случайным порядком букв.

Рекомендуется использовать функцию https://docs.python.org/3/library/random.html#random.shuffle

Для отладки зафиксируйте генератор, чтобы он всегда возвращал одни и те же значения с помощью https://docs.python.org/3/library/random.html#random.seed

_В задаче используется 42_

Напишите функцию **disc_generator(alphabet)**, которая принимает на вход упорядоченный список (строку), а возвращает случайным образом перемешанный (тоже строку).

***Примечание.*** В этой задаче не нужно ничего считывать и ничего выводить на печать. Только реализовать функцию.

Sample Input 1:

```commandline
ABCDEFGHIJKLMNOPQRSTUVWXYZ
```

Sample Output 1:

```commandline
QMJZTGFKPWLSBOXNCRYEVHIADU
```

Sample Input 2:

```commandline
0123456789
```

Sample Output 2:

```commandline
7328569401
```

Sample Input 3:

```commandline
АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ
```

Sample Output 3:

```commandline
ЪЕКПЩЛЦЖУМРЙЬОШФЮБНТВСХГЭДЫЯИЧАЗ
```
