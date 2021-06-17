## 17

Переменная df содержит DataFrame.

Переменная group_by содержит имя колонки по которой производится группировка.

Найдите количество записей каждого типа, сгруппированным по значению в колонке group_by.

Например, если group_by='animal', то для первого Dataframe надо получить таблицу с количеством каждого вида животных: кошек, собак, змей.

**Sample Input 1:**

```commandline
df = pd.DataFrame({'animal': ['cat', 'cat', 'snake', 'dog', 'dog', 'cat', 'snake', 'cat', 'dog'],
                   'age': [2.5, 3, 0.5, np.nan, 5, 2, 4.5, np.nan, 7],
                   'name': ['Murzik', 'Pushok', 'Kaa', 'Bobik', 'Strelka', 'Vaska', 'Kaa2', 'Murka', 'Graf'],
                   'visits': [1, 3, 2, 3, 2, 3, 1, 1, 2],
                   'priority': ['yes', 'yes', 'no', 'yes', 'no', 'no', 'no', 'yes', 'no']})
                 index = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'])
group_by = "animal"
```

**Sample Output 1:**

```commandline
cat      4
dog      3
snake    2
Name: animal, dtype: int64
```

**Sample Input 2:**

```commandline
df = pd.DataFrame({'name' : ["Alex", "Bob", "Carmen", "Diaz", "Ella","Forman"],
                   'age' : [20, 27, 35, 55, 18, 21],
                   'designation': ["VP", "CEO", "CFO", "VP", "VP", "CEO"]})
group_by = "designation"
```

**Sample Output 2:**

```commandline
VP     3
CEO    2
CFO    1
Name: designation, dtype: int64
```
