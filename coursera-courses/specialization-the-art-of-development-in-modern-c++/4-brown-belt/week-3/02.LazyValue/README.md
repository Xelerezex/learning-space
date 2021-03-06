## Lazy Value

Иногда на практике встречаются объекты, создание которых занимает значительное время, однако они бывают нужны
не при каждом запуске программы. Например, клиент системы контроля версий может обращаться к локальным файлам,
а может — к удалённому репозиторию. Тогда устанавливать соединение с удалённым репозиторием можно, только
если пользователь решил к нему обратиться.

Для представления таких объектов может быть полезен шаблон ```LazyValue<T>```. У него есть константный метод
```const T& Get()```, который возвращает ссылку на созданный объект. В своём конструкторе ```LazyValue```
принимает инициализирующую функцию, которая используется при первом вызове метода ```Get``` для создания
хранимого объекта. Последующие вызовы ```Get``` просто возвращают ссылку на хранимый объект.

Таким образом, объект класса ```LazyValue<T>``` не тратит время на создание хранимого объекта до первого
вызова метода ```Get```.

Вам дан интерфейс шаблона ```LazyValue```. Реализуйте его. Более подробный список требований:

-   Объект класса ```LazyValue<T>``` не должен конструировать объект типа ```T``` при своём создании

-   При первом вызове метода ```LazyValue<T>::Get``` должен создаваться объект типа ```T``` с помощью функции,
    переданной в конструктор ```LazyValue<T>```

-   Последующие вызовы метода ```Get``` не должны вызывать функцию, переданную в конструктор

-   Если за время жизни объекта ```LazyValue<T>``` метод ```Get``` не был вызван ни разу, то инициализирующая
    функция не должна быть вызвана.

-   Шаблон ```LazyValue``` должен поддерживать работу с типами без конструктора по умолчанию

Интерфейс шаблона приведён в заготовке решения.

### Заготовка решения

>   [lazy_value.cpp](https://d3c33hcgiwev3.cloudfront.net/pMJLn_Y7Eei5Kg7DUflKxA_a53d6e10f63b11e88717b75766913400_lazy_value.cpp?Expires=1647388800&Signature=FS2uJYh08eQJIeB95FKsOcTkigazKpWMsgVC1P~lZVt4mX0BSuwCiA-twP5ETRFjaP3GgbZgmCXXpVRyH4oV9QXGrbOTtEzhTg5pNI0g-dhv9nWJhsCqviCMUl4mpWqrzXZ1Jh47y40dOj93CsZ0QqHn2iY2s0FoZJzJijg012Q_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
