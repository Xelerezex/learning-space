Реализуйте функцию "отражатель". Пока для нас она аналогична ротору, за 2 исключениями:

-   Имеет только 1 направление
-   Отражатель с функцией шифрования всегда соединяет символы парами

Реализуйте 2 отражателя:

-   0 - без шифрования
-   1 - отражатель вида "B"

Спецификация на Отражатели (и таблица соответствия символов) - http://www.codesandciphers.org.uk/enigma/rotorspec.htm



Реализуйте функцию reflector(symbol, n):

-   symbol - символ, поступающий для шифрования
-   n - номер отражателя

**Sample Input 1:**

```commandline
text = ABCDEFGHIJKLMNOPQRSTUVWXYZ
disk = 0
```

**Sample Output 1:**

```commandline
Reflected: ABCDEFGHIJKLMNOPQRSTUVWXYZ
```

**Sample Input 2:**

```commandline
text = ABCDEFGHIJKLMNOPQRSTUVWXYZ
disk = 1
```

**Sample Output 2:**

```commandline
Reflected: YRUHQSLDPXNGOKMIEBFZCWVJAT
```

**Sample Input 3:**

```commandline
text = SOME CLEAR TEXT
disk = 0
```

**Sample Output 3:**

```commandline
Reflected: SOMECLEARTEXT
```

**Sample Input 4:**

```commandline
text = SOME ENCRYPTED TEXT FOR EXAMPLE
disk = 1
```

**Sample Output 4:**

```commandline
Reflected: FMOQQKUBAIZQHZQJZSMBQJYOIGQ
```
