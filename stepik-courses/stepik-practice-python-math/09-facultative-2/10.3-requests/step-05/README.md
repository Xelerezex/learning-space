Простая задача на get запрос и проверку ответа.

На вход подаётся url, к которому необходимо сделать простой get запрос.

Если в ответ получен статус 200 (т.е. всё хорошо, сервер отдал документ), то необходимо вывести на печать тело полученного ответа.

Если ответ отличается от 200, то надо вывести сообщение об ошибке:

```commandline
Упс, произошла ошибка!..
Код ошибки - #ERROR_CODE#
```

Заменив #ERROR_CODE# на код ошибки (код ответа)

**Sample Input 1:**

```commandline
https://stepik.org/media/attachments/lesson/254899/1.txt
```

**Sample Output 1:**

```commandline
Hello, World!
```

**Sample Input 2:**

```commandline
https://stepik.org/media/attachments/lesson/254899/2.txt
```

**Sample Output 2:**

```commandline
Упс, произошла ошибка!..
Код ошибки - 404
```

**Sample Input 3:**

```commandline
https://stepik.org/media/attachments/lesson/254899/menu.json
```

**Sample Output 3:**

```python
{"menu": {

  "id": "file",

  "value": "File",

  "popup": {

    "menuitem": [

      {"value": "New", "onclick": "CreateNewDoc()"},

      {"value": "Open", "onclick": "OpenDoc()"},

      {"value": "Close", "onclick": "CloseDoc()"}

    ]

  }

}}
```

**Sample Input 4:**

```commandline
https://stepik.org/media/attachments/lesson/254899/index.html
```

**Sample Output 4:**

```html
<!DOCTYPE html>

<html lang='ru-ru'>

    <head>

        <title>Минимально валидный HTML</title>

    </head>

    <body>

        <p>Этот HTML отображается в браузере и проходит валидацию w3org</p>

    </body>

</html>
```
