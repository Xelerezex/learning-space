Вам дана последовательность строк.

Выведите строки, содержащие **"cat"** в качестве **слова**.

**Примечание:**

Для работы со словами используйте группы символов **\b** и **\B**.

Описание этих групп вы можете найти в [документации](https://docs.python.org/3.5/library/re.html).

**Sample Input:**
```commandline
cat
catapult and cat
catcat
concat
Cat
"cat"
!cat?
```


**Sample Output:**
```commandline
cat
catapult and cat
"cat"
!cat?
```


