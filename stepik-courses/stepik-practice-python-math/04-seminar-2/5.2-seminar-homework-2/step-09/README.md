## C1. mimic_dict

Напишите функцию mimic_dict(string), которая принимает на вход строковую переменную (может содержать пробелы, табуляцию, переносы строк), возвращающую «имитирующий» словарь, который соотносит каждое появившееся слово, со списком всех слов, которые следуют за этим словом.

Для "входа" в словарь используйте в качестве ключа пустую строку, в соответствие которой будет поставлено 1 слово.

Примечание. В этой задаче не нужно ничего считывать и ничего выводить на печать. Только реализовать функцию.

**Sample Input 1:**

```commandline
Uno dos tres cuatro cinco
```

**Sample Output 1:**

```commandline
{"": ["Uno"], "Uno": ["dos"], "dos": ["tres"], "tres": ["cuatro"], "cuatro": ["cinco"]}
```

**Sample Input 2:**

```commandline
a cat and a dog
a fly
```

**Sample Output 2:**

```commandline
{"": ["a"], "a": ["cat", "dog", "fly"], "cat": ["and"], "and": ["a"], "dog": ["a"]}
```