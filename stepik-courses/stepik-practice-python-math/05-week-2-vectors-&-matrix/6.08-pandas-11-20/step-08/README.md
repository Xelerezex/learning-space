## 15

Переменная df содержит DataFrame.

Переменная group_by содержит имя колонки по которой производится группировка.

Найдите средние значение возраста по всем записям, сгруппированным по значению в колонке group_by и выведите на печать.

Например, если group_by='animal', то для первого Dataframe надо получить таблицу со средними для каждого вида животных: кошек, собак, змей.

**Sample Input 1:**

```commandline
df = pd.DataFrame({'animal': ['cat', 'cat', 'snake', 'dog', 'dog', 'cat', 'snake', 'cat', 'dog', 'dog'],
                   'age': [2.5, 3, 0.5, np.nan, 5, 2, 4.5, np.nan, 7, 3],
                   'name': ['Murzik', 'Pushok', 'Kaa', 'Bobik', 'Strelka', 'Vaska', 'Kaa2', 'Murka', 'Graf', 'Muhtar'],
                   'visits': [1, 3, 2, 3, 2, 3, 1, 1, 2, 1],
                   'priority': ['yes', 'yes', 'no', 'yes', 'no', 'no', 'no', 'yes', 'no', 'no']})
                 index = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'])
group_by = "animal"
```

**Sample Output 1:**

```commandline
animal
cat      2.5
dog      5.0
snake    2.5
Name: age, dtype: float64
```

**Sample Input 2:**

```commandline
df = pd.DataFrame({'name' : ["Alex", "Bob", "Carmen", "Diaz", "Ella","Forman", "Glen"],
                   'age' : [20, 27, 35, 55, 18, 21, 35],
                   'designation': ["VP", "CEO", "CFO", "VP", "VP", "CEO", "MD"]})
group_by = "designation"
```

**Sample Output 2:**

```commandline
designation
CEO    24
CFO    35
MD     35
VP     31
Name: age, dtype: int64
```
