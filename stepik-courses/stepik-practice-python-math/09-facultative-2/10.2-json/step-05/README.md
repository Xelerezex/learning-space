Переменная inData содержит JSON.

Сохраните в переменную outData полноценный python объект ("распарсите" json).

**Примечание.** _В этой задаче не нужно ничего считывать и ничего выводить на печать. Только реализовать функцию._

**Sample Input 1:**

```commandline
inData = '{"one": ["http", "yandex.ru"], "two": ["https", "google.com"]}'
```

**Sample Output 1:**

```commandline
<class 'dict'>
{'one': ['http', 'yandex.ru'], 'two': ['https', 'google.com']}
```
outData:

**Sample Input 2:**

```commandline
inData = '[{"id": 1, "login": "admin"}, {"id": 2, "login": "user"}]'
```

**Sample Output 2:**

```commandline
outData:
<class 'list'>
[{'id': 1, 'login': 'admin'}, {'id': 2, 'login': 'user'}]
```
