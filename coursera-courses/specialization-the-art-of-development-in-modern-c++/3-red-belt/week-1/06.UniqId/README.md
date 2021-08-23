## Uniq Id

Разработать макрос UNIQ_ID, который будет формировать идентификатор, уникальный в пределах данного cpp-файла.
Например, следующий код должен компилироваться и работать:

```c++
int UNIQ_ID = 5;
string UNIQ_ID = "hello!";
```

В рамках данной задачи допускается, что код

```c++
int UNIQ_ID = 5; string UNIQ_ID = "hello"; // оба определения на одной строке
```

не будет компилироваться. Заготовка решения:

> [unique_id.cpp](https://d3c33hcgiwev3.cloudfront.net/bLqqyWNWEeiEZRKxXgWFpg_6d0dd340635611e8b15785f60e62d699_uniq_id.cpp?Expires=1629849600&Signature=YSb9cJXuOVyVDejhBub4ryFUXEp5cP9HjclqnQo0WM9nAvsBx8jxFrKoiV-wDeKP9j-idsFQkbabCRwNGNMQWmUaWuPK3qCEw5sI9mzfgfaGJfxs8P5SUIkmCSZak6ZOhqA40Fvn7JSb4iIXjJLkFTdwaXMK1rDyDy1q4sdpXkg_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

Подсказки:

-    подумайте, как можно применить макрос __LINE__

-    ознакомьтесь с конкатенацией в макросах, а также с макросами в качестве параметров других макросов по ссылкам ниже:

1.     [Основы](https://www.iar.com/knowledge/learn/programming/basics-of-using-the-preprocessor)

2.     [Самое интересное](https://www.iar.com/knowledge/learn/programming/advanced-preprocessor-tips-and-tricks)
