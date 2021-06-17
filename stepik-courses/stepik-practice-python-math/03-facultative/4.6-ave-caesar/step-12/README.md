## Шифрование пирата Кидда своими руками

Реализуйте функцию шифрования, которую использовал пират Кидд из рассказа Эдгара Аллана По "[Золотой жук](https://ru.wikipedia.org/wiki/%D0%97%D0%BE%D0%BB%D0%BE%D1%82%D0%BE%D0%B9_%D0%B6%D1%83%D0%BA_(%D1%80%D0%B0%D1%81%D1%81%D0%BA%D0%B0%D0%B7))".

Используйте словарь:

```commandline
Символ  8   ;   4   ‡   )   *   5   6   (   1   †   0   9   2   :   3   ?   ¶   -   .
Буква   e   t   h   o   s   n   a   i   r   f   d   l   m   b   y   g   u   v   c   p
```

Символы, отсутствующие среди шифруемых букв (пробелы, знаки препинания, кириллица, буква "x" и т.п.) необходимо пропускать.

Реализуйте функцию kidds_encryption(text, reverse=False), которая возвращает зашифрованный (или наоборот расшифрованный) текст.

-    text - исходный текст
-    reverse - признак расшифровки, если находится в значении True, это значит, что функцию надо использовать для расшифровки текста (по умолчанию False)

**Sample Input 1:**

```commandline
ethosnairfdlmbyguvcp
```

**Sample Output 1:**

```commandline
Encryption:      8;4‡)*56(1†092:3?¶-.
Decryption back: ethosnairfdlmbyguvcp
```

**Sample Input 2:**

```commandline
XxL ,L, LxX
```

**Sample Output 2:**

```commandline
Encryption:      000
Decryption back: lll
```

**Sample Input 3:**

```commandline
A good glass in the bishop's hostel
```

**Sample Output 3:**

```commandline
Encryption:      53‡‡†305))6*;4826)4‡.)4‡);80
Decryption back: agoodglassinthebishopshostel
```

**Sample Input 4:**

```commandline
in the devil's seat forty-one degrees
```

**Sample Output 4:**

```commandline
Encryption:      6*;48†8¶60))85;1‡(;:‡*8†83(88)
Decryption back: inthedevilsseatfortyonedegrees
```

**Sample Input 5:**

```commandline
and thirteen minutes northeast and
```

**Sample Output 5:**

```commandline
Encryption:      5*†;46(;88*96*?;8)*‡(;485);5*†
Decryption back: andthirteenminutesnortheastand
```

**Sample Input 6:**

```commandline
by north main branch seventh limb
```

**Sample Output 6:**

```commandline
Encryption:      2:*‡(;4956*2(5*-4)8¶8*;40692
Decryption back: bynorthmainbranchseventhlimb
```

**Sample Input 7:**

```commandline
east side shoot from the left eye of
```

**Sample Output 7:**

```commandline
Encryption:      85);)6†8)4‡‡;1(‡9;48081;8:8‡1
Decryption back: eastsideshootfromthelefteyeof
```

**Sample Input 8:**

```commandline
the death's-head a bee line from the
```

**Sample Output 8:**

```commandline
Encryption:      ;48†85;4)485†528806*81(‡9;48
Decryption back: thedeathsheadabeelinefromthe
```
