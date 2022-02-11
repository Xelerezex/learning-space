## Secondary Index

Часто от хранилища данных требуется быстрый поиск по любому полю. Для этого конструируются
вспомогательные структуры данных, ускоряющие поиск, они называются вторичными индексами
(```secondary index```). Реализуйте такое хранилище для данных типа ```Record``` ниже:

```cpp
struct Record {
    string id;
    string title;
    string user;
    int timestamp;
    int karma;
};

class Database {
    public:
        bool Put(const Record& record);
        const Record* GetById(const string& id) const;
        bool Erase(const string& id);

        template <typename Callback>
        void RangeByTimestamp(int low, int high, Callback callback) const;

        template <typename Callback>
        void RangeByKarma(int low, int high, Callback callback) const;

        template <typename Callback>
        void AllByUser(const string& user, Callback callback) const;
};

```

-   Операция ```Put``` должна возвращать ```true```, если вставка удалась, и ```false```, если вставка
    не удалась, потому что в базе данных уже есть запись с таким же ```id```. В последнем случае
    состояние базы данных не должно меняться.

-   Операция ```GetById``` должна возвращать ```nullptr```, если в базе данных нет записи с
    указанным ```id```.

-   Операция ```Erase``` должна возвращать ```true```, если удалось удалить элемент с заданным ```id```,
    и ```false```, если элемент с заданным ```id``` не был найден. В последнем случае состояние базы
    данных не должно меняться.

-   Операции ```RangeByTimestamp```, ```RangeByKarma``` и ```AllByUser``` принимают функтор
    ```callback```. Подразумевается, что он имеет оператор ```()```, принимающий в качестве
    аргумента объект типа ```Record``` и возвращающий ```bool```.

-   Операция ```RangeByTimestamp``` должна обходить все записи, у которых поле ```timestamp```
    находится в диапазоне ```[low, high]``` (обе границы включены), и для каждой из них один раз
    вызывать ```callback```. Если очередной вызов ```callback``` вернул ```false```, итерация
    прекращается.

-   Операция ```RangeByKarma``` должна обходить все записи, у которых поле ```karma``` находится в
    диапазоне ```[low, high]```.

-   Операция ```AllByUser``` должна обходить все записи в хранилище данных, у которых поле ```user```
    равно значению параметра ```user```.

-   Так же, как и ```RangeByTimestamp```, методы ```RangeByKarma``` и ```AllByUser``` должны вызывать
    ```callback``` для каждой записи, по которой они итерируются, и прекращать итерацию, если
    ```callback``` вернул ```false```.

-   Параметр ```callback``` позволяет управлять процессом обхода: он должен возвращать ```true```,
    если требуется продолжить обход найденных записей, и ```false``` в противном случае. Например,
    это позволит вывести первые **10** записей или найти первую запись, удовлетворяющую дополнительному
    критерию.

-   Время выполнения всех операций должно иметь в среднем сублинейную (например, константную или
    логарифмическую) зависимость от общего числа записей в базе данных.

-   Все границы интервалов - включительные, ```[low, high]``` — это наиболее универсальный
    интервальный запрос, подумайте, как с помощью него выразить условия вида
    ```x < high, x > low, x = x_0```.

-   При решении этой задачи вы можете считать, что ```bad_alloc``` кидаться не будет.

### Заготовка решения

>   [secondary_index.cpp](https://d3c33hcgiwev3.cloudfront.net/Ur49UvlMEeiTKQ5ajE7PqA_5329a8f0f94c11e899124f41a69d460f_secondary_index.cpp?Expires=1644710400&Signature=k2Pf2YnzVL4N5NjLzYmUWI-iRjyY7AjqiYxVvxEHiqDEkXxf50HBzTrXwSY9~0zU5AEmgwd2fj0tZO44ON~SbXzYOUabxLklP9tukVToe2Vy09RAwMXIx64mamGbWMqjV~MNRovbcoxYGp6RoJgcT8veEcm-0e8otbHc3eOPCHY_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

### Примечание

В этой задаче может оказаться полезен контейнер [multimap](https://en.cppreference.com/w/cpp/container/multimap).
Мы не рассматривали его в лекциях, однако вам не составит труда в нём разобраться — он отличается от
обычного map только тем, что может хранить повторяющиеся ключи.

### Подсказки

Для этой задачи есть набор подсказок, которые должны помочь вам с решением. Если вам не удаётся
решить задачу и вы чувствуете, что у вас кончились идеи, вы можете ими воспользоваться. Но сначала
обязательно попробуйте решить задачу без подсказок.

> [secondary_index_hint_1.pdf](https://d3c33hcgiwev3.cloudfront.net/g8F3qQNyEem5_xLqNrIdUA_842541a0037211e984a94bba8e170847_secondary_index_hint_1.pdf?Expires=1644710400&Signature=KssipgxxpZAV8yBaS1c8bVVPEi1j6GicK9Ss-Iq9EsFx5v9T3gITocTUv0MW5j9Q7-l-WiIUEfs5BYKE-AWWo-9bBcGiyCUF2hY4UYSkpYXxs~4gCJ5EUai1F8h-5OXZ6~HCCLI~Khw~G~D-Rvbj~hnAShV0ehgOxMqod5TvuLc_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [secondary_index_hint_2.pdf](https://d3c33hcgiwev3.cloudfront.net/g8FP6wNyEemYdRIT0BhLtg_8424f380037211e99ce679dc1edaa265_secondary_index_hint_2.pdf?Expires=1644710400&Signature=F1YIL1qTYOyCR~R1J5USWPApR2iUpH0CfJo1eqWAgRePBG8uhPf9ePaGzq5QCSdhSsTWWb6QPgjl6cobeVe~HG5hpi~rZ96G1Li-h9M~O5r40tvKAYIlG7aQNagZ4d9BKMb067DlpHzPKzmmi1wVgYnuJdCPvBLpLfzC8Inmo~Y_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [secondary_index_hint_3.pdf](https://d3c33hcgiwev3.cloudfront.net/nq8Uuj5fEem4egrIUlgmqg_9fa8b6003e5f11e98e1811b7b0df8f93_secondary_index_hint_3.pdf?Expires=1644710400&Signature=LNfpISJNz21U~GCMkTaORzQjoixl-sw9Va8G-in9Sebi2RGXIIESiOjLx-clxf1~cYevngyUvjLju8gQfQ9~nlWQ7sAjnlgEBRwlQ8BTBSvXc02OAtpRvJCdA3m34SsKJpOi41tLD2PYprJRViqmUH7ns6JLsXVaoLu7NwE5kJM_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
