
C2. print_mimic

Напишите функцию print_mimic(mimic_dict, word), которая принимает на вход 2 параметра:

1. **словарь**, идентичный тому который возвращает mimic_dict(string) из задачи А:

```python
{"": ["a"], "a": ["cat", "dog", "fly"], "cat": ["and"], "and": ["a"], "dog": ["a"]}
```

2. **строку** (1-е слово, с которого надо начать текст)


С помощью mimic dict довольно легко вернуть случайные текст, который имитирует оригинал. Выберите слово, затем посмотрите какие слова могут появиться дальше, и выберите одно из них наугад, после чего повторите процедуру.

Верните строку длиной 200 слов через пробел.

Используйте пустую строку в качестве первого слова для простых примеров.

Если вы застряли со словом, которое не находится в словаре (например, оно было последним в исходном тексте, преобразованном с помощью mimic_dict(string)), вернитесь к пустой строке, чтобы продолжить.


**Примечание 1.** Для выбора случайного элемента из списка используйте random.choice(list), не забыв импортировать модуль  random.


**Примечание 2.** В этой задаче не нужно ничего считывать и ничего выводить на печать. Только реализовать функцию.


**Sample Input:**

```commandline
We are not what we should be
We are not what we need to be
But at least we are not what we used to be
  -- Football Coach
```

**Sample Output:**

```commandline
We are not what we need to be -- Football Coach We are not what we should be -- Football Coach We are not what we are not what we are not what we should be But at least we should be We are not what we should be But at least we used to be -- Football Coach We are not what we need to be But at least we are not what we are not what we need to be -- Football Coach We are not what we are not what we need to be We are not what we used to be But at least we should be -- Football Coach We are not what we are not what we need to be We are not what we should be But at least we should be -- Football Coach We are not what we used to be -- Football Coach We are not what we need to be We are not what we should be We are not what we are not what we used to be But at least we used to be But at least we should be -- Football Coach We are not what
```
