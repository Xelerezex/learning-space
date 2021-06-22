Переменная inData содержит полноценный python объект.

Сохраните в переменную outData строку, представляющую из себя JSON.

**Примечание.** _В этой задаче не нужно ничего считывать и ничего выводить на печать. Только реализовать функцию._

**Sample Input 1:**

```commandline
inData = {
    "one": ["http", "yandex.ru"],
    "two": ["https", "google.com"]
}
```

**Sample Output 1:**

```commandline
outData:
<class 'str'>
{"one": ["http", "yandex.ru"], "two": ["https", "google.com"]}
```

**Sample Input 2:**

```commandline
inData = [
    {
        "id": 1,
        "login": "admin"
    },
    {
        "id": 2,
        "login": "user"
    }
]
```

**Sample Output 2:**

```commandline
outData:
<class 'str'>
[{"id": 1, "login": "admin"}, {"id": 2, "login": "user"}]
```
