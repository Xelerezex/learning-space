## Умножение по "схеме мудреца" с конкатенацией

Напишите функцию wisdom_multiplication(x, y, length_check = True), реализующую умножение по схеме мудреца с прошлого шага.

1.    Вычитаем из 100 первое и второе число.
2.    Складываем результаты шага 1.
3.    Вычитаем из 100 результат шага 2.
4.    Перемножаем результаты шага 1.
5.    Результат шага 3 даёт первые цифры результата, а результат шага 4 даёт последние 2 цифры результата.

В зависимости от значения аргумента length_check функция проверяет или нет длину результата шага 4 и при необходимости дописывает 0 перед ним (если результат всего 1 цифра).

Функция должна возвращать целое число.

***Примечание.*** В этой задаче не нужно ничего считывать и ничего выводить на печать. Только реализовать функцию.

Sample Input 1:

```commandline
96x97
```

Sample Output 1:

```commandline
9312
```

Sample Input 2:

```commandline
99x99
length_check=True
```

Sample Output 2:

```commandline
9801
```

Sample Input 3:

```commandline
99x99
length_check=False
```

Sample Output 3:

```commandline
981
```

Sample Input 4:

```commandline
10x10
```

Sample Output 4:

```commandline
-808100
```

Sample Input 5:

```commandline
91x99
```

Sample Output 5:

```commandline
9009
```
