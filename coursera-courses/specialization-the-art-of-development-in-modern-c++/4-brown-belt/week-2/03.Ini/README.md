## Ini

В лекциях мы разработали библиотеки для загрузки данных из форматов ```XML``` и ```JSON```,
поместив каждую из них в своё пространство имён. В этой задаче вам нужно сделать то же самое
для формата ```INI```. Вам надо разработать библиотеку со следующим интерфейсом

```cpp
using Section = unordered_map<string, string>;

class Document
{
    public:
        Section& AddSection(string name);
        const Section& GetSection(const string& name) const;
        size_t SectionCount() const;

    private:
        unordered_map<string, Section> sections;
};

Document Load(istream& input);
```

Требования:

-   Содержимое библиотеки должно находиться в пространстве имён ```Ini```

-   Интерфейс, приведённый выше, должен быть объявлен в файле **ini.h**

-   На проверку пришлите архив с полной реализацией библиотеки, в архиве должен быть файл **ini.h**

-   В процессе тестирования функции ```Load``` ей на вход будет подаваться текст в формате

```commandline
[секция 1]
ключ1=значение1
ключ2=значение2

[секция 2]
ключ3=значение3
ключ4=значение4
```

-   Гарантируется, что в наших тестах используются только корректные **ini**-файлы, то есть строки вида
    ```ключ=значение``` всегда находятся внутри какой-то секции и содержат ровно один символ '**=**'

-   Строка **ini**-файла либо пустая, либо не содержит ведущих пробелов

Примеры применения библиотеки смотрите в юнит-тестах в файле **test_ini.cpp**

### Замечание

Возможно, вам придётся добавить поддержку ```unordered_map``` в своей версии файла **test_runner.h**

### Частичный набор тестов для библиотек

>   [test_ini.cpp](https://d3c33hcgiwev3.cloudfront.net/alT_dgU9Eem6Gg6vVM6M8A_6abd0ff0053d11e982e74bb8b133285d_test_ini.cpp?Expires=1645833600&Signature=jVz5ollbHaoBDyBuuEaNDs~hW1F5sp4O2LvRoj~ZaLDzBWytZuHTe6nBWk0-glM8skOVdCeJkI9nUWPl9561QUgPaM45cHLppQNThOniy-M2KVvrsU1FbB-8FCTm4IMMrAVR1rdXLQiX0erMJ1fENLRnadNRcHOUIm1R6eEGWDg_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
