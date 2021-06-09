Реализуйте функцию caesar(text, key, alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'), расширяющую возможности функции с предыдущего шага.

Ваша функция должна корректно работать с любым переданным алфавитом, а если алфавит не передан, то использовать английский.

**Примечание.** В этой задаче не нужно ничего считывать и ничего выводить на печать. Только реализовать функцию.

**Sample Input 1:**

```commandline
3

Ave, Caesar
```

**Sample Output 1:**

```commandline
Encrypted: DYHFDHVDU
Decrypted back: AVECAESAR
```

**Sample Input 2:**

```commandline
-3
ABCDEFGHIJKLMNOPQRSTUVWXYZ
dyhfdhvdu
```

**Sample Output 2:**

```commandline
Encrypted: AVECAESAR
Decrypted back: DYHFDHVDU
```

**Sample Input 3:**

```commandline
1
АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ
А с русским текстом выйдет?
```

**Sample Output 3:**

```commandline
Encrypted: БТСФТТЛЙНУЁЛТУПНГЬКЕЁУ
Decrypted back: АСРУССКИМТЕКСТОМВЫЙДЕТ
```

**Sample Input 4:**

```commandline
13
ABCDEFGHIJKLMNOPQRSTUVWXYZАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ
А что, если это будет смесь, Runglish? Let me speak from my heart!.. Заметьте, что буквы A и А визуально идентичны, так что на бумаге мы вряд ли расшифровали бы такое...
```

**Sample Output 4:**

```commandline
Encrypted: МEЯЫСЮШХKЯЫНAРСЯЮЩСЮJДЖАTYVЕUYRЁZRЕВRNXSДБZZКURNДЁФМЩСЯJЯСEЯЫНAЧОINХМОХФAМШJЪЫХРСЪЯХEЪIЯМЧEЯЫЪМНAЩМПСЩIОЭMРШХЭМЮFХBЭЫОМШХНIЯМЧЫС
Decrypted back: АЧТОЕСЛИЭТОБУДЕТСМЕСЬRUNGLISHLETMESPEAKFROMMYHEARTЗАМЕТЬТЕЧТОБУКВЫAИАВИЗУАЛЬНОИДЕНТИЧНЫТАКЧТОНАБУМАГЕМЫВРЯ
```
