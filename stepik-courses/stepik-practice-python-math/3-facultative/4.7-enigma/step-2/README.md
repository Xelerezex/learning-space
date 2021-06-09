Реализуйте функцию Ротора шифрования.

![alt tag](https://github.com/Xelerezex/learning-space/tree/learning-space/stepik-courses/stepik-practice-python-math/3-facultative/4.7-enigma/step-2/Source/1.png)

Фактически это простая замена символа по словарю.

Учитывайте, что ротор имеет "прямое" и "обратное" направления.

Т.е. если сигнал идёт напрямую и символ **"A"** соответствует **"E"**, то при обратном движении сигнала символу **"E"** будет соответствовать символ **"А"**

Реализуйте функцию с 4 роторами:

-    0 - "не шифрованный ротор" - возвращает всегда тот же символ, что и принимает (в любом направлении)
-    1-3 - роторы номер 1, 2 и 3 соответственно.

Спецификация на роторы (и таблица соответствия символов) - http://www.codesandciphers.org.uk/enigma/rotorspec.htm

![alt tag](https://github.com/Xelerezex/learning-space/tree/learning-space/stepik-courses/stepik-practice-python-math/3-facultative/4.7-enigma/step-2/Source/2.png)

Реализуйте функцию rotor(symbol, n, reverse=False)

-    symbol - символ, поступающий для шифрования
-    n - номер ротора
-    reverse - признак обратного направления, если находится в значении True, это значит, что функцию надо использовать в обратном направлении. (по умолчанию False)

Возвращает строку с зашифрованным символом

![alt tag](https://github.com/Xelerezex/learning-space/tree/learning-space/stepik-courses/stepik-practice-python-math/3-facultative/4.7-enigma/step-2/Source/3.png)

***Подсказка.***

_Сэр, я надеюсь вы не станете забивать словарь для сопоставления символов вручную? Выжпрограммист, сэр! Я бы обратил внимание на вторую таблицу, там символы составлены в циклические цепочки (очень похожие на словари, которые мы использовали в предыдущем уроке). По сути они показывают переход символов друг в друга:_


**Sample Input 1:**

```commandline
text = ABCDEFGHIJKLMNOPQRSTUVWXYZ
disk = 0
```

**Sample Output 1:**

```commandline
Encryption (forward): ABCDEFGHIJKLMNOPQRSTUVWXYZ
Decryption (forward): ABCDEFGHIJKLMNOPQRSTUVWXYZ

Encryption (back): ABCDEFGHIJKLMNOPQRSTUVWXYZ
Decryption (back): ABCDEFGHIJKLMNOPQRSTUVWXYZ
```

**Sample Input 2:**

```commandline
text = ABCDEFGHIJKLMNOPQRSTUVWXYZ
disk = 1
```

**Sample Output 2:**

```commandline
Encryption (forward): EKMFLGDQVZNTOWYHXUSPAIBRCJ
Decryption (forward): ABCDEFGHIJKLMNOPQRSTUVWXYZ

Encryption (back): UWYGADFPVZBECKMTHXSLRINQOJ
Decryption (back): ABCDEFGHIJKLMNOPQRSTUVWXYZ
```

**Sample Input 3:**

```commandline
text = SOME CLEAR TEXT
disk = 0
```

**Sample Output 3:**

```commandline
Encryption (forward): SOMECLEARTEXT
Decryption (forward): SOMECLEARTEXT

Encryption (back): SOMECLEARTEXT
Decryption (back): SOMECLEARTEXT
```

**Sample Input 4:**

```commandline
text = SOME ENCRYPTED TEXT FOR EXAMPLE
disk = 3
```

**Sample Output 4:**

```commandline
Encryption (forward): GYZJJNFWQEAJHAJSALYWJSBZEVJ
Decryption (forward): SOMEENCRYPTEDTEXTFOREXAMPLE

Encryption (back): XZVPPNGIOHJPBJPKJCZIPKTVHFP
Decryption (back): SOMEENCRYPTEDTEXTFOREXAMPLE
```
