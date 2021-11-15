## Group Heavy Strings

Дан набор строк. Необходимо разбить их на группы, в каждой из которых все строки
имеют одинаковый набор символов.

Например, если даны строки **law**, **port**, **top**, **laptop**, **pot**,
**paloalto**, **wall**, **awl**, нужно разбить их на 4 группы:

-    строки, состоящие только из букв **a**, **l** и **w**: **law**, **wall**, **awl**;

-    строки, состоящие только из букв **o**, **p**, **r** и **t**: **port**;

-    строки, состоящие только из букв **o**, **p** и **t**: **top**, **pot**;

-    строки, состоящие только из букв **a**, **l**, **o**, **p**, **t**:
    **laptop**, **paloalto**.

Разбиение на группы должно быть реализовано в виде функции
```cpp
    template <typename String>
    vector<Group<String>> GroupHeavyStrings(vector<String> strings);
```

Здесь ```Group<String>``` — синоним для ```vector<String>```:
```cpp
    template <typename String>
    using Group = vector<String>;
```

Наличие такого синонима позволяет записать возвращаемый тип функции ```GroupHeavyString```
в виде ```vector<Group<String>>```, что читается понятнее, чем ```vector<vector<String>>```.

Слова в каждой группе должны располагаться в том же порядке, что и в исходном наборе.
При этом порядок самих групп значения не имеет.

Строка типа ```String``` не обязана состоять из символов типа ```char```. Тип символа
можно получить с помощью выражения typename ```String::value_type``` или ```Char<String>```,
если определить соответствующий синоним:

```cpp
    template <typename String>
    using Char = typename String::value_type;
```

Сам тип *String* может быть, например, обычной строкой (*string*) или вектором символов.

Про тип ```Char<String>``` известно следующее:

-    Объекты этого типа можно сравнивать с помощью операторов == и <.

-    «Тяжёлыми» могут быть не только сами строки, но и отдельные символы. Поэтому их
     можно свободно перемещать, **но скопировать каждый символ в функции можно не более
     одного раза (без учёта копирования при передаче аргумента strings по значению)**.
     В противном случае вы получите вердикт «неправильный ответ» с соответствующим
     комментарием.

#### Ограничения

За 1 секунду функция должна обработать максимум 100000 строк длины не более 100.
При оценке сложности можете считать, что копирование каждого символа стоит порядка
100 элементарных операций.

#### Файл с заготовкой решения

> [group_heavy_strings.cpp](https://d3c33hcgiwev3.cloudfront.net/w56UtGWhEeiUPhLykNFyig_c3ca5f8065a111e880287db1087a8bac_group_heavy_strings.cpp?Expires=1637107200&Signature=ZIHvMEppDvRxAg-Qxb5x5F2XbJDd2zIpduIwX9XPqxtM~hFn~e71KxS0IwdLWtuThVPd45Jgx9GqB0z7jVbUTTGoiJWm8aWALASNrmqNoUCmgbDOcxeHy35akYo-zkFeUyRCBYqvH7v52VhGGpDzaFTeU~l11Tce9wa7NAHgzxI_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
