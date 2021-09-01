## Paginator

В лекции мы разработали функцию Head, которая позволяет пройтись циклом for по началу контейнера.
В этой задаче мы сделаем шаг вперёд и разработаем шаблон Paginator, который разбивает содержимое контейнера на несколько страниц.
Классический пример, когда такое может пригодиться на практике, — это распределение списка мобильных приложений по экранам телефона.
Допустим, у нас есть вектор всех приложений нашего телефона и на одном экране мы можем разместить 20 иконок приложений.
Тогда распределить приложения по экранам мы можем вот таким кодом:

```c++
vector<vector<Application>> DistributeAmongScreens(const vector<Application>& apps) {
    vector<vector<Application>> result;
    for (const auto& page : Paginate(apps, 20)) {
        result.push_back({page.begin(), page.end()});
    }
    // result[0] - все приложения, которые попадают на первый экран,
    // result[1] - все приложения, которые попадают на второй экран и т.д.
    return result;
}
```


Заметьте, наш код получился коротким и элегантным.
Нам не пришлось писать какой-то отдельный код для обработки последнего экрана,
который может содержать меньше 20 приложений.


Итак, разработайте шаблон класса Paginator со следующими свойствами:

-   он имеет один шаблонный параметр — тип итератора

-   конструктор класса Paginator<Iterator> принимает три параметра:

1.  Iterator begin

2.  Iterator end — пара итераторов begin и end задают полуинтервал [begin; end), который мы будем нарезать на страницы

3.  size_t page_size — размер одной страницы

-   по объектам класса Paginator<Iterator> можно проитерироваться с помощью цикла range-based for

-   класс Paginator<Iterator> имеет метод size_t size() const, который возвращает количество страниц,
    на которые был разбит переданный контейнер

-   сами страницы должны так же поддерживать итерацию с помощью range-based for и иметь метод size_t size() const,
    возвращающий количество объектов в этой странице

-   подробные примеры использования смотрите в юнит-тестах в шаблоне решения

Кроме того разработайте шаблон функции Paginate, которая принимает ссылку на контейнер и размер страницы,
и возвращает объект класса Paginator<It>:

```c++
template <typename C> ??? Paginate(C& c, size_t page_size)
```

Файл с заготовкой решения задачи:

> [paginator.cpp](https://d3c33hcgiwev3.cloudfront.net/-qGdtHYQEei8FQ6TnIKJEA_fb073cf0761011e887545d40e262c3fc_paginator.cpp?Expires=1630627200&Signature=Qk3by-WAD0QURNFpsBCmDnbiBa54IsMmd6NR~WyGgG-WLEBNpvXGo9~sIIvttY1~S0bWz~WR7SbvyXJsuGmyRdp787lCDoxXHNi~OBE2RpJzzR1L5mO1KfGQTCXrQamz3GQ8OF8nhHErIHEhA8Q5ieIdikTCueCNID-LYyzT-GA_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

Возможно, в шаблоне у вас будет некорректно работать вызов ASSERT_EQUAL в функции TestLooping.
Разберитесь, почему это происходит, внесите правку в свою локальную версию файла test_runner.h,
чтобы подобная ошибка не возникала в других задачах.

**Подсказки**

Для этой задачи есть набор подсказок, которые должны помочь вам с решением. Если вам не удаётся решить
задачу и вы чувствуете, что у вас кончились идеи, вы можете ими воспользоваться. Но сначала обязательно
попробуйте решить задачу без подсказок.

> [Подсказка 1](https://d3c33hcgiwev3.cloudfront.net/sngDpmP_EeiigxLHv6mB7A_b2aa5dc063ff11e894900bafcb351264__________-1.pdf?Expires=1630627200&Signature=TtZx2EWkhJrekgZMHTcdeCkUtZLLM9v28okiC07JSrr~mJG2eM82yq38poH0jrbtfWMTY5DKqr3GOzn~ai0iSmFkpj7RtKnjJMz3iNqIRFVmX-Dac0Vj-UrRGs3jsKhV9bjBvDGkREYq2taYjAZCmWnN1kEFMlt65yqsgOtAFv4_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [Подсказка 2](https://d3c33hcgiwev3.cloudfront.net/v3J2VGP_EeiaEg6Thd1Wwg_bf9e19e063ff11e894900bafcb351264__________-2.pdf?Expires=1630627200&Signature=fKzv2cePpS5U0Bhvn73YG85Dr6fOPTvm1vHzoS94PJY5a5ML5XhIDRdcGbqzo4-xb0v0sAaTCLR-Ezn6ozSzhEgg4tTjXq93s~NmhW09GoW1dspiuzxONy87pTPTvA6Khem--ib8DWRj2fbfmJPuAEeMvPP5UPD8lqrGtArv3Q8_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [Подсказка 3](https://d3c33hcgiwev3.cloudfront.net/5pf2sZZFRuOX9rGWRebjzA_f1f5dbfc16b54aaf8235eb41d233d92f_Podskazka-3.pdf?Expires=1630627200&Signature=Z-mg~toXNEQ-~qQv0-f0ro9D5kwPCfzcItJPQSRODoK1pezZRUGq0zMqbTC76Hjgm1vWmBJF~jzpH5udJFpH6NoaPn1sJrYTjWIxiaud3lzXjGCkvZWrIMqHneX7Ne38~jqvSvKikWo4mrbkbNHSGHX6K8DA-d6wzQt-7Hj66l0_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
