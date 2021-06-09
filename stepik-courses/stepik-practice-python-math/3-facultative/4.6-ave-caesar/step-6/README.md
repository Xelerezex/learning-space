Реализуйте функцию jarriquez_encryption(text, key, alphabet='ABCDEFGHIJKLMNOPQRSTUVWXYZ', reverse=False), возвращающую зашифрованный текст, по алгоритму описанному на предыдущем шаге.

-    text - исходный текст
-    key - ключ шифрования (число)
-    alphabet - алфавит (по умолчанию английский)
-    reverse - признак расшифровки, если находится в значении True, это значит, что функцию надо использовать для расшифровки текста, т.к. каждый сдвиг должен быть отрицательным. (по умолчанию False)

Из преобразуемого текста удаляются все пробелы и знаки препинания. Зашифрованный текст пишется в верхнем регистре 1 строкой.

**Примечание.** В этой задаче не нужно ничего считывать и ничего выводить на печать. Только реализовать функцию.

**Sample Input 1:**

```commandline
У СУДЬИ ЖАРРИКЕСА ПРОНИЦАТЕЛЬНЫЙ УМ
423
АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ
reverse=False
```

**Sample Output 1:**

```commandline
ЧУЦИЮЛКВУФКНЙУГУТССКЩДФИПЮРЯЛЦР
```

**Sample Input 2:**

```commandline
ЧУЦИЮЛКВУФКНЙУГУТССКЩДФИПЮРЯЛЦР
423
АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ
reverse=True
```

**Sample Output 2:**

```commandline
УСУДЬИЖАРРИКЕСАПРОНИЦАТЕЛЬНЫЙУМ
```

**Sample Input 3:**

```commandline
Some encripted text for this assignment
26101986
```

**Sample Output 3:**

```commandline
UUNEFWKXKVUEECMDVLPRUQQYCYTIHWUKPZ
```

**Sample Input 4:**

```commandline
UUNEFWKXKVUEECMDVLPRUQQYCYTIHWUKPZ
26101986

reverse=True
```

**Sample Output 4:**

```commandline
SOMEENCRIPTEDTEXTFORTHISASSIGNMENT
```
