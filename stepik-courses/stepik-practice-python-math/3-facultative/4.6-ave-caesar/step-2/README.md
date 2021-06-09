Реализуйте функцию caesar(text, key), возвращающую зашифрованный текст, работающую только с латинским алфавитом.

-    text - исходных текст, который надо зашифровать (или расшифровать)
-    key - ключ (сдвиг)

Ключ может быть отрицательным или больше 26

Из преобразуемого текста удаляются все пробелы и знаки препинания. Зашифрованный текст пишется в верхнем регистре 1 строкой.


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
dyhfdhvdu
```

**Sample Output 2:**

```commandline
Encrypted: AVECAESAR
Decrypted back: DYHFDHVDU
```

**Sample Input 3:**

```commandline
13
THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG
```

**Sample Output 3:**

```commandline
Encrypted: GURDHVPXOEBJASBKWHZCFBIREGURYNMLQBT
Decrypted back: THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG
```

**Sample Input 4:**

```commandline
42
In cryptography, a Caesar cipher, also known as Caesar's cipher, the shift cipher, Caesar's code or Caesar shift, is one of the simplest and most widely known encryption techniques. It is a type of substitution cipher in which each letter in the plaintext is replaced by a letter some fixed number of positions down the alphabet.
```

**Sample Output 4:**

```commandline
Encrypted: YDSHOFJEWHQFXOQSQUIQHSYFXUHQBIEADEMDQISQUIQHISYFXUHJXUIXYVJSYFXUHSQUIQHISETUEHSQUIQHIXYVJYIEDUEVJXUIYCFBUIJQDTCEIJMYTUBOADEMDUDSHOFJYEDJUSXDYGKUIYJYIQJOFUEVIKRIJYJKJYEDSYFXUHYDMXYSXUQSXBUJJUHYDJXUFBQYDJUNJYIHUFBQSUTROQBUJJUHIECUVYNUTDKCRUHEVFEIYJYEDITEMDJXUQBFXQRUJ
Decrypted back: INCRYPTOGRAPHYACAESARCIPHERALSOKNOWNASCAESARSCIPHERTHESHIFTCIPHERCAESARSCODEORCAESARSHIFTISONEOFTHESIMPLES
```
