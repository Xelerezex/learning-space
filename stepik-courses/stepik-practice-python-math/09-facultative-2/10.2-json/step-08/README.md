Улучшите задачу из предыдущего шага, сделав JSON человеко-читаемым.

В качестве отступа используйте 4 пробела.

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
{
    "one": [
        "http",
        "yandex.ru"
    ],
    "two": [
        "https",
        "google.com"
    ]
}
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
[
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
