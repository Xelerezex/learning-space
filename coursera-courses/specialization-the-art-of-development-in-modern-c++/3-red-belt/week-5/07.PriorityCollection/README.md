## Priority Collection

Реализуйте шаблонный контейнер ```PriorityCollection```, позволяющий хранить объекты некопируемого типа,
а также совершать с ними следующие операции:

-    добавить элемент с нулевым приоритетом;

-    добавить набор элементов с нулевыми приоритетами;

-    увеличить на 1 приоритет заданного элемента;

-    извлечь из контейнера элемент с максимальным приоритетом.

Поскольку добавление элемента заключается в его перемещении в контейнер, метод увеличения приоритета не
может принимать сам элемент. Поэтому метод, добавляющий элементы, для каждого из них должен вернуть некий
идентификатор, который затем можно использовать для вызова других методов.

Тип идентификатора — ```PriorityCollection::Id``` — вы должны выбрать самостоятельно. Он должен быть
легко копируемым: например, числом, указателем или итератором. Примеры определения и использования
типа ```Id``` вы можете найти в шаблоне решения.

### Структура класса

```cpp
template <typename T>
class PriorityCollection {
    public:
        using Id = /* тип, используемый для идентификаторов */;

        // Добавить объект с нулевым приоритетом
        // с помощью перемещения и вернуть его идентификатор
        Id Add(T object);

        // Добавить все элементы диапазона [range_begin, range_end)
        // с помощью перемещения, записав выданные им идентификаторы
        // в диапазон [ids_begin, ...)
        template <typename ObjInputIt, typename IdOutputIt>
        void Add(ObjInputIt range_begin, ObjInputIt range_end,
               IdOutputIt ids_begin);

        // Определить, принадлежит ли идентификатор какому-либо
        // хранящемуся в контейнере объекту
        bool IsValid(Id id) const;

        // Получить объект по идентификатору
        const T& Get(Id id) const;

        // Увеличить приоритет объекта на 1
        void Promote(Id id);

        // Получить объект с максимальным приоритетом и его приоритет
        pair<const T&, int> GetMax() const;

        // Аналогично GetMax, но удаляет элемент из контейнера
        pair<T, int> PopMax();

    private:
        // Приватные поля и методы
};
```

### Гарантии

-    Вы можете полагаться на то, что для элементов типа T определены перемещение и сравнение на ==,
     != и <. Все операции над элементами имеют константную сложность.

-    Гарантируется, что все добавляемые элементы различны, однако добавленный и затем извлечённый
     элемент может быть добавлен вновь.

-    Методы **Get** и **Promote** всегда вызываются от валидных с точки зрения метода **IsValid**
     идентификаторов.

-    Методы **GetMax** и **PopMax** вызываются только при наличии элементов в контейнере.

-    При наличии нескольких элементов с одинаковым максимальным приоритетом необходимо выбирать и
     извлекать тот, который был добавлен позже остальных.

### Файл с заготовкой решения

> [priority_collection_2.cpp](https://d3c33hcgiwev3.cloudfront.net/770LKHF7EeiMwApe4i-fLg_f0609e20717b11e896e2ffa1280778ad_priority_collection_2.cpp?Expires=1637798400&Signature=i2eka2UOttKaac962jnzxAaL~H15p5vLlb6gPn0uopMaKdLhzLXiXzTL3GVss2VE-VU7eDRFv6LCjYfm~Nqawm~4gZjqyVB-TcTdzutwGcJ7s~u64SO2TX4n3LlMhwTZdMwF7dvsvLYYUiGKhOOzaSeXY5QSUJo8M6CQe~sqJ3Y_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

### Ограничения

Контейнер должен обрабатывать 10^6 запросов не более чем за 1 секунду. Гарантируется, что суммарная
длина диапазонов, с которыми вызывается вторая версия метода Add, также не превосходит 10^6.

### Подсказки

Если задача вызывает непреодолимые трудности, вы можете воспользоваться подсказками. Они помогут
быстрее сдать задачу, но в итоге вы получите меньше пользы от процесса поиска решения.

Не нужно открывать все подсказки сразу. Используйте их последовательно.

> [priority-collection-1.pdf](https://d3c33hcgiwev3.cloudfront.net/EMf97ufhEeilxxL_ZeRz_A_110331c0e7e111e8a449e572c9acd20b_priority-collection-1.pdf?Expires=1637798400&Signature=QdWoWBGWJNEfUOxqA-iN39Cx9pLxw7aPFuR3qfZzG0awn3PLofg0RVHsdeuGuKlxwi1Q5-qJMQt6Nwb2NyIK9M2-kVXbYtYWQs1lroRY5oJMZ108iZzrbDfktArfieT2Fh8dQC3k02rz6jbQlR7Vt0ohlXrSGhG73OPQEpy~s6M_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [priority-collection-2.pdf](https://d3c33hcgiwev3.cloudfront.net/EMjoT-fhEeilxxL_ZeRz_A_1101ab20e7e111e8b0ed5909629489a2_priority-collection-2.pdf?Expires=1637798400&Signature=glHq5q8BgtVZhUXMKUhffLZJd7uGjTubxTRSTTzt7TO2hiVLYVHh9QJk5tMpBH2lTL2FbBIbtd1WBT2agdK4oiVKCGdPM1S~ue6oq8xBUphdZlIEeJrLa8BpPob9r8agDsGHy~YjUlH8agg7kPGW9awtipEgpWKWp78LpXAar2U_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [priority-collection-3.pdf](https://d3c33hcgiwev3.cloudfront.net/EMoguefhEeiixgqCUDoEfA_11473fa0e7e111e89bf1032d5d05de4f_priority-collection-3.pdf?Expires=1637798400&Signature=jmwSbp0fKCN~F9miSgee2FEVmnoTQvx23Yf-F1ELVb5xEBD5-HOE3domZAN~S6TlwLKIEyrWJISgEEoAWIJhijUKx6z66ZctRNCoiW8Z81cvZPEDeV--4p3zkVNPDia0ypOLh1b16EirLWxewlWpoZtM90Jx5qycreMdEtVUuc0_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [priority-collection-4.pdf](https://d3c33hcgiwev3.cloudfront.net/EMk2cOfhEeilxxL_ZeRz_A_114c96d0e7e111e88c94d51cedeec544_priority-collection-4.pdf?Expires=1637798400&Signature=YpsFusBXy4BvHZlONrTW1PMcrUgwWaEw30ISc3drK2kyvICZGtc3FN~CxDHnV7zCoNN102yJ8OyWngGcu1Hs0YDJUoiUSwxg-i2lYERtQu80DHCLLNg3GCC~H9cZQmWsCSBq3PtnzoEtE9h8c6R1CJTTNvnQ~BXqfCsy0WxTIcU_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
