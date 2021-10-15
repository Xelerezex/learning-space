## Airport Counter

### Условие

Вам необходимо разработать простейшую систему сбора статистики вылетов для небольших авиакомпаний.
Высокоуровневые требования выглядят следующим образом:

1.  Система сбора статистики должна представлять собой класс `AirportCounter`, умеющий в произвольный
    момент времени для заданного аэропорта вернуть текущее количество вылетов из него.

2.  Набор возможных аэропортов фиксирован в виде enum и потому не может изменяться в рамках одного
    сеанса работы системы статистики, то есть в рамках одного экземпляра `AirportCounter`.
    Таким образом, класс `AirportCounter` необходимо шаблонизировать типом этого enum: если назвать
    такой `enum TAirport`, получим шаблонный класс `AirportCounter<TAirport>`.

3.  Гарантируется (по крайней мере, обещано заказчиком), что по `enum` аэропортов можно будет
    легко определить количество элементов в нём, а также перебрать сами элементы. А именно, любой
    используемый `enum` будет иметь вид
    `enum class SomeCityAirport { Airport1, Airport2, ..., AirportN, Last_ };`, то есть будет
    содержать некоторое количество элементов-аэропортов и элемент `Last_` в качестве последнего.
    Поскольку в этом `enum` не будут заданы числовые значения для элементов, можно полагаться на то,
    что они будут пронумерованы подряд от 0 до N-1, а выражение
    `static_cast<uint32_t>(SomeCityAirport::Last_)` будет содержать количество аэропортов *(N)*.

4.  Класс должен уметь конструироваться по списку аэропортов вылета, а также позволять обновлять
    этот список: добавить вылет из какого-то аэропорта, удалить один вылет (например, ошибочно
    добавленный) или удалить из истории все вылеты из некоторого аэропорта.

### Тестирование

Прежде чем перейти к более детальному описанию интерфейса класса, опишем процесс тестирования задачи.

**Вам будут даны все тесты**, на которых будет проверяться шаблонный класс AirportCounter.
Ваша задача — добиться не только корректной работы на этих тестах, но и уложиться на них в
**2 секунды**. (Считайте, что заказчик предоставил вам подробнейшие сценарии использования вашего
класса, которые затем были преобразованы в конкретные бенчмарки.)

Таким образом, вы должны выбрать способ реализации класса, ориентируясь лишь на конкретные бенчмарки.

Отметим, что данные бенчмарки составлены на основе реального примера из высоконагруженного сервиса,
замедление которого даже на десятки процентов недопустимо. Именно поэтому в этой задаче важно не
только спроектировать решение с приемлемой асимптотической сложностью, но и «разогнать» его на
конкретных примерах.

### Интерфейс класса

```cpp
template <typename TAirport>
class AirportCounter {
public:
    // конструктор по умолчанию: список элементов пока пуст
    AirportCounter();

    // конструктор от диапазона элементов типа TAirport
    template <typename TIterator>
    AirportCounter(TIterator begin, TIterator end);

    // получить количество элементов, равных данному
    size_t Get(TAirport airport) const;

    // добавить данный элемент
    void Insert(TAirport airport);

    // удалить одно вхождение данного элемента
    void EraseOne(TAirport airport);

    // удалить все вхождения данного элемента
    void EraseAll(TAirport airport);

    using Item = pair<TAirport, size_t>;

    // получить некоторый объект, по которому можно проитерироваться,
    // получив набор объектов типа Item - пар (аэропорт, количество),
    // упорядоченных по аэропорту
    ??? GetItems() const;

private:
    // ???
};
```

### Файл с заготовкой решения и тестами

> [airport_counter.cpp](https://d3c33hcgiwev3.cloudfront.net/5zBNao5FEeiEShL6YrwsWg_e7740c708e4511e8bccc6fe6f3f3ac49_airport_counter.cpp?Expires=1634428800&Signature=Xl5tcRw1skzERX2~hYoPjxvIcySJduYcbZXheGhyVX1EZspsYAD-2J6QqKPT8kuSeWGGr5A7N8XQi70S7HWx7u054-X4oN7yV8-xNrqd-7XmTW1TogIM2D0UrRye6K2ls4~Xs5EkbfCIui0Erdhdw9~n7HDvjjsu84UqZx~0VZw_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

### Подсказки

Если задача вызывает непреодолимые трудности, вы можете воспользоваться подсказками.
Они помогут быстрее сдать задачу, но в итоге вы получите меньше пользы от процесса поиска решения.

Не нужно открывать все подсказки сразу. Используйте их последовательно.

> [aiport-counter-1.pdf](https://d3c33hcgiwev3.cloudfront.net/nWXgJufgEeiTKQ5ajE7PqA_9de262b0e7e011e89896f778454779b5_airport-counter-1.pdf?Expires=1634428800&Signature=G3PHvm8elfQQAotDl2M0s0jQ0fhO~G7zoizKkHQVIM63MGf~ezlN3syFWBeWqQsr7rkAG6bm9VomXHuMfTta9D3r7qe6etPjxwQw76sWFyER36Lf0elqcEIj0v-1jVp1~10wb21y2ffj1GjB6zECwO3Jif5oy5XmSRHbI~AT4OM_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [aiport-counter-2.pdf](https://d3c33hcgiwev3.cloudfront.net/nWSAZOfgEeilxxL_ZeRz_A_9de19f60e7e011e8acc76fdfd2237641_airport-counter-2.pdf?Expires=1634428800&Signature=UPeymgIB03oByfF8X0U6cq5jYhwUZ0ySRPx8IF9LfxpnSBdPgVhG4KWvJjxKfSvw~VuJWuYy1RhBPU4yt0PLrrVcM2x71TFhRtJr~mrUls46tBaLs447~v0CFICxrw5dCFw69u7AVZkFYcSt8~IKJFATi0253KPuoPfuuDA-vIM_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
