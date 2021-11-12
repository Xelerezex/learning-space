## Josephus Permutation

Дан диапазон объектов некоторого типа. Напишите функцию, переставляющую его элементы в соответствии с
порядком, определённым так называемой [считалкой Иосифа](https://ru.wikipedia.org/wiki/%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0_%D0%98%D0%BE%D1%81%D0%B8%D1%84%D0%B0_%D0%A4%D0%BB%D0%B0%D0%B2%D0%B8%D1%8F) с заданным размером шага:

```cpp
template <typename RandomIt>
void MakeJosephusPermutation(
    RandomIt range_begin, RandomIt range_end,
    uint32_t step_size
);
```

Гарантируется, что итераторы range_begin и range_end являются итераторами произвольного доступа,
то есть допускают вычитание одного из другого и сложение с числом. Кроме того, вы можете полагаться на
то, что step_size > 0. Тип переупорядочиваемых объектов можно получить с помощью выражения typename
RandomIt::value_type. **Объекты этого типа запрещено копировать**. При наличии копирования этих объектов
вы получите ошибку компиляции.

#### Ограничения

Максимальный размер диапазона — 10^5, максимальный размер шага — 10^2. Время выполнения одного
вызова функции ограничено 1 секундой.

#### Решение с копированиями

Вам дано решение данной задачи, копирующее элементы и не укладывающееся в ограничения по времени,
но в остальном корректное. Вы можете исправить его или написать своё.

> [josephus_permutation.cpp](https://d3c33hcgiwev3.cloudfront.net/ZEjC7YNdROCIwu2DXXTgLg_55cac981187c48b182abcb899353d0d8_josephus_permutation.cpp?Expires=1636848000&Signature=WpgZX6Vna3a3bADjxgbOZTDc907UC9ggZIOZJd0Tepy7QwBAQr9Pp8npLWK0MLlRB-MOP4qAbgXt-SMGzDWwAWktAjEkSsjlSSpgmPbTaevGwixT1JMEopjRUaBuHGaBpbKtKGpdAj5uWLRFj5TYMQNbk0zgmqdviEVgS~XHxXk_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
