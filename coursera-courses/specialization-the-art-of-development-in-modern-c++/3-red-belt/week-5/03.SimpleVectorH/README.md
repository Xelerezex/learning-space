## Simple Vector

В видеолекции мы с вами познакомились с конструктором копирования и оператором присваивания,
а также написали конструктор копирования для SimpleVector. В этой задаче вам нужно реализовать
оператор присваивания для SimpleVector.

Напомним, что следующий код вызывает конструктор **копирования**:

```cpp
SimpleVector<int> source(5);
SimpleVector<int> dest = source; // Конструктор копирования
```

А код ниже — **оператор присваивания**:

```cpp
SimpleVector<int> source(5);
SimpleVector<int> dest;
dest = source; // Оператор присваивания
```

Вам дан cpp-файл, который подключает заголовочный файл simple_vector.h и содержит небольшой набор
юнит-тестов. Пришлите на проверку файл simple_vector.h с реализацией оператора присваивания.

> [simple_vector_copy_assignment](https://d3c33hcgiwev3.cloudfront.net/tYwSAmszEei5FgrpHNEYyg_b5e1fa306b3311e8a97f951115d198a4_simple_vector_copy_assignment.cpp?Expires=1637193600&Signature=cuBf3s9PE4Di8TihmvRlH0gqy7yNxwLPOPsyeFHjsNoPU6GMW0SLj8VQuZ2qtA05A2Nmzurl0uYh3~bzjVHvyQkwnFlVMAHdfby2~Pn66sos-MZuj5jVJsMQKvIDKhPHG15cxkAGCvBO-AWYmUsMBK~0uRpHGbGdeogNyQbtZA0_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
