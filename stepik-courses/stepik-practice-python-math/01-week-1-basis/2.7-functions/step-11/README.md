

Напишите функцию перевода числа из десятичной системы счисления в систему с основанием n

Функция translate должна принимать 2 параметра:

-   обязательный (исходное целое число в десятичной системе счисления)
-   необязательный, по-умолчанию 2 (основание новой системы счисления, в которую переводится число)

***Примечание 1.*** Все новые системы счисления имеют основание меньше 10

***Примечание 2.*** В этой задаче не нужно ничего считывать и ничего выводить на печать. Только реализовать функцию.



Для перевода из привычной нам десятичной системы исчисления в систему по основанию n, необходимо:

1.   разделить исходное число на n
2.   записать остаток от деления (шаг 1)
3.   для результата деления (шаг 1) повторить операцию с шага 1
4.   если результат деления равен 0, прекратить операцию
5.   Составить число в новой системе счисления из остатков (от последнего вычисленного к первому)
**
На [примере перевода из десятичной системы в двоичную](https://ru.wikipedia.org/wiki/%D0%94%D0%B2%D0%BE%D0%B8%D1%87%D0%BD%D0%B0%D1%8F_%D1%81%D0%B8%D1%81%D1%82%D0%B5%D0%BC%D0%B0_%D1%81%D1%87%D0%B8%D1%81%D0%BB%D0%B5%D0%BD%D0%B8%D1%8F#.D0.9F.D1.80.D0.B5.D0.BE.D0.B1.D1.80.D0.B0.D0.B7.D0.BE.D0.B2.D0.B0.D0.BD.D0.B8.D0.B5_.D0.B4.D0.B5.D1.81.D1.8F.D1.82.D0.B8.D1.87.D0.BD.D1.8B.D1.85_.D1.87.D0.B8.D1.81.D0.B5.D0.BB_.D0.B2_.D0.B4.D0.B2.D0.BE.D0.B8.D1.87.D0.BD.D1.8B.D0.B5) :

Допустим, нам нужно перевести число 19 в двоичное. Вы можете воспользоваться следующей процедурой :

>    19 /2 = 9 с остатком 1

>    9 /2 = 4 c остатком 1

>    4 /2 = 2 без остатка 0

>    2 /2 = 1 без остатка 0

>    1 /2 = 0 с остатком 1

Итак, мы делим каждое частное на 2 и записываем остаток в конец двоичной записи. Продолжаем деление до тех пор, пока в частном не будет 0. Результат записываем справа налево. То есть нижняя цифра (1) будет самой левой и т.д. В результате получаем число 19 в двоичной записи: **10011** .

**Sample Input 1:**

```commandline
19
```

**Sample Output 1:**

```commandline
10011
```


**Sample Input 2:**

```commandline
19 7
```


**Sample Output 2:**

```commandline
25
```


**Sample Input 3:**

```commandline
10 2
```


**Sample Output 3:**

```commandline
1010
```


**Sample Input 4:**

```commandline
8 3
```


**Sample Output 4:**

```commandline
22
```

