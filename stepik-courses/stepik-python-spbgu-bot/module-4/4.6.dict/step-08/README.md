Программе на вход подается число nnn и список из nnn имен. Для каждого имени программа должна посчитать количество раз, которое имя встречается в списке и вывести это в формате "{Имя}: {Количество}", причем список должен быть отсортирован в алфавитном порядке. Чтобы проитерироваться по отсортированному списку ключей словаря d можно воспользоваться таким циклом: for i in sorted(d):, а чтобы обратиться к словарю по еще не инициализированному ключу можно воспользоваться методом d.get(key, 0)(здесь первым аргументом является ключ, а вторым объект, который вернет метод, если этот ключ еще не был инициализирован).

**Sample Input:**

```commandline
10
Артём
Николай
Эрнст
Иван
Сергей
Данил
Антон
Дмитрий
Иван
Дмитрий
```

**Sample Output:**

```commandline
Антон: 1
Артём: 1
Данил: 1
Дмитрий: 2
Иван: 2
Николай: 1
Сергей: 1
Эрнст: 1
```