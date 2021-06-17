## Энигма v0.1

Пришло время собрать нашу собственную Энигму!

Пока наша машина будет довольно простой. Мы просто разместим 3 ротора и 1 отражатель.

Спецификации роторов и отражателем используются из предыдущих задач.

Смещения и движение роторов/отражателей отсутствуют. Фактически мы реализуем примеры 1 и 2 с предыдущего шага.

Для проверки алгоритма и одного из алфавитов можно использовать пример http://www.codesandciphers.org.uk/enigma/example1.htm

Реализуйте функцию enigma(text, ref, rot1, rot2, rot3), где:

-    text - исходный текст, который необходимо зашифровать
-    ref - номер отражателя (согласно задаче https://stepik.org/lesson/283487/step/3)
-    rot1, rot2, rot3 - номера роторов (согласно задаче https://stepik.org/lesson/283487/step/2)

Функция возвращает зашифрованный текст.

Сигнал распространяется по машине справа налево (и после отражения обратно):

![alt tag](https://github.com/Xelerezex/learning-space/tree/learning-space/stepik-courses/stepik-practice-python-math/3-facultative/4.7-enigma/step-5/Source/1.png)

**Sample Input 1:**

```commandline
enigma('A', 1, 1, 0, 0)
```

**Sample Output 1:**

```commandline
H
```

**Sample Input 2:**

```commandline
enigma('A', 1, 1, 2, 3)
```

**Sample Output 2:**

```commandline
U
```

**Sample Input 3:**

```commandline
enigma('U', 1, 1, 2, 3)
```

**Sample Output 3:**

```commandline
A
```

**Sample Input 4:**

```commandline
enigma('ABCDEFGHIJKLMNOPQRSTUVWXYZ', 1, 1, 2, 3)
```

**Sample Output 4:**

```commandline
UEJOBTPZWCNSRKDGVMLFAQIYXH
```

**Sample Input 5:**

```commandline
enigma('Some encripted text', 1, 1, 2, 3)
```

**Sample Output 5:**

```commandline
LDRBBKJMWGFBOFBYF
```

**Sample Input 6:**

```commandline
enigma('LDRBBKJMWGFBOFBYF', 1, 1, 2, 3)
```

**Sample Output 6:**

```commandline
SOMEENCRIPTEDTEXT
```
