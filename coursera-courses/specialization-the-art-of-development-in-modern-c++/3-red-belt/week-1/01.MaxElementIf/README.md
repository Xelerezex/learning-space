## Max Element If

#### Предисловие

Если вы не уверены, стоит ли вам сначала пройти более ранние наши курсы, или у вас достаточно знаний, чтобы начать с «Красного пояса», попробуйте решить эту задачу.
Если вы не понимаете её условие или не можете быстро решить, скорее всего, вам надо сначала пройти «Жёлтый пояс»

#### Условие задачи

Реализуйте шаблонную функцию

```cpp
template<typename ForwardIterator, typename UnaryPredicate>
ForwardIterator max_element_if(
    ForwardIterator first, ForwardIterator last, UnaryPredicate pred);
```

возвращающую итератор на максимальный элемент в диапазоне *[first, last)*,
для которого предикат *pred* возвращает *true*. Если диапазон содержит несколько подходящих элементов с максимальным значением,
то результатом будет первое вхождение такого элемента. Если диапазон не содержит подходящих элементов,
то функция должна вернуть *last*.

Гарантируется, что:

-    *pred* принимает аргумент того типа, который имеют элементы диапазона
-    для *ForwardIterator* определены операторы ++, ==, !=, * (разыменование)
-    для типа, на который указывает итератор, определён оператор < («меньше»)

Заготовка решения:

> [max_element_if.cpp](https://d3c33hcgiwev3.cloudfront.net/7qo4B-kGR3aqOAfpBvd2fQ_6d73daac052a40d78a7c7877e7e3ca26_max_element_if.cpp?Expires=1629504000&Signature=FsT4dZjrg5J31DdQBWON0mKlTVN9vAiaXLGXjc5BfPFiYiXYPxbAcs4QpTo5I11eBnIXxaFPDvkiuEMBSYYCchI7Fls--~3KYYafIyTm97YY97cNuRsnMYH34Pp60U0bT1xkD6lKmi31chCLUKIvitqMyq6RRP4pU4TmqTQbmmA_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

Автор задачи — Ольга Марчевская

P.S. В файле *max_element_if.cpp* используется заголовочный файл *test_runner.h*. Это юнит-тест фреймворк, который мы разработали в «Жёлтом поясе по C++».

> [test_runner.h](https://d3c33hcgiwev3.cloudfront.net/XN7SE3VQEeiMwApe4i-fLg_5d0dd060755011e8ae137556d6d83af9_test_runner.h?Expires=1629504000&Signature=Dya9Ln-n-W8SBF-A8mqUR2iX0Uvus4KpTnJw1u3kitpC28lidVFFagtbEYHcKKdGe-FR7a3VtAwfpYsPXwMaAYr4KvYW7wA06qNOV8mLRkUXEy~reKUU6Hy~hCj1zzKj8VDLxKE3Mq-dUMVV9yz4Y1pKvrJ6USiVI47DhlriVr4_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
