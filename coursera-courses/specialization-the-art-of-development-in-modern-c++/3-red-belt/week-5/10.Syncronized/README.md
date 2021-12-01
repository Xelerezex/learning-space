## Synchronized

Мы уже не раз видели, что отсутствие синхронизации доступа нескольких потоков к одним и тем же данным
может фатально сказаться на работе программы. Поэтому очень важно не забывать захватывать мьютекс
при обращении к разделяемым данным. Но если у нас есть большой проект, в котором доступ к общим данным
осуществляется из большого количества мест в коде, то не так уж и трудно забыть сделать это, внося
очередные правки.

Чтобы защититься от такой забывчивости, можно написать специальную обёртку над данными, которая будет
предоставлять к ним доступ только под мьютексом. В этой задаче вам надо разработать такую обёртку —
шаблон класса ```Synchronized``` вот с таким интерфейсом:

```cpp
template <typename T>
class Synchronized {
    public:
        explicit Synchronized(T initial = T());

        struct Access {
            T& ref_to_value;
        };

        Access GetAccess();
    private:
        T value;
};
```

Тип ```Access``` должен быть структурой, в которой есть поле ```T& ref_to_value```, ссылающееся на поле
```value``` класса ```Synchronized<T>```. Кроме того объект класса ```Access``` должен вести себя
аналогично классу ```lock_guard<mutex>```: захватывать мьютекс в своём конструкторе и освобождать в
деструкторе. Пример:

```cpp
Synchronized<int> s_int;
{
    auto access = s_int.GetAccess();
    // Критическая секция начинается отсюда и продолжается до конца блока
    access.ref_to_value = 5;
}
ASSERT_EQUAL(s_int.GetAccess().value, 5);
```

Вам можно (и даже нужно) добавлять необходимые поля в класс ```Access``` и шаблон ```Synchronized```.
Более подробные примеры использования шаблона ```Synchronized``` смотрите в заготовке решения.

Как видите, единственный способ получить доступ к полю ```value``` класса ```Synchronized<T>``` — это
обратиться к полю ```ref_to_value``` класса ```Access```, который гарантирует, что этот доступ
осуществляется под мьютексом. Таким образом, если разделяемые данные обернуть в шаблон ```Synchronized```,
вы никогда не забудете захватить мьютекс при обращении к ним.

>   [synchronized.cpp](https://d3c33hcgiwev3.cloudfront.net/9r2ajXu4EeiGPw6YfDtP_A_f717a1407bb811e894b8ab62fb634057_synchronized.cpp?Expires=1638489600&Signature=atpQOOOgzW3uOgWs6J1tjKMDEdIzbG5SedSn0SUsQl4eFVIfaqCsE65-50QAC3uAISy86UYA-Z~Pe5QzIRqM~NLATggDt0QPPjQitn9MojVkRbYlPgNgp0I~Ff5HlC3Dghacwb1JPuYS9sVxK3CEKRsa1qsDzoisFVkRUkK5ios_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
