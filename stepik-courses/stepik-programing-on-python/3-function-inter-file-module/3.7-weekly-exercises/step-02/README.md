## Дополнительная

В какой-то момент в Институте биоинформатики биологи перестали понимать, что говорят информатики: они говорили каким-то странным набором звуков.

В какой-то момент один из биологов раскрыл секрет информатиков: они использовали при общении [подстановочный шифр](https://ru.wikipedia.org/wiki/%D0%A8%D0%B8%D1%84%D1%80_%D0%BF%D0%BE%D0%B4%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%BA%D0%B8),

т.е. заменяли каждый символ исходного сообщения на соответствующий ему другой символ. Биологи раздобыли ключ к шифру и теперь нуждаются в помощи:

Напишите программу, которая умеет шифровать и расшифровывать шифр подстановки. Программа принимает на вход две строки одинаковой длины, на первой строке записаны символы исходного алфавита, на второй строке — символы конечного алфавита, после чего идёт строка, которую нужно зашифровать переданным ключом, и ещё одна строка, которую нужно расшифровать.

Пусть, например, на вход программе передано:
abcd
*d%#
abacabadaba
#*%*d*%

Это значит, что символ a исходного сообщения заменяется на символ _*_ в шифре, _b_ заменяется на _d_, _c_ — на _%_ и _d_ — на _#_.

Нужно зашифровать строку *abacabadaba* и расшифровать строку _#*%*d*%_ с помощью этого шифра. Получаем следующие строки,

которые и передаём на вывод программы:

*d*%*d*#*d*

dacabac

Sample Input 1:

```commandline
abcd
*d%#
abacabadaba
#*%*d*%
```


Sample Output 1:

```commandline
*d*%*d*#*d*
dacabac
```


Sample Input 2:

```commandline
dcba
badc
dcba
badc

```

Sample Output 2:

```commandline
badc
dcba
```

