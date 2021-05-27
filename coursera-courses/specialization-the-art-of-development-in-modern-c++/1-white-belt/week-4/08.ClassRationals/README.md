## Class Rational

***Общее описание***

В этой задаче вам надо разработать класс для представления рациональных чисел и внедрить его в систему типов языка *С++* так, чтобы им можно было пользоваться естественным образом. Задание состоит из нескольких частей. К каждой части приложен файл с заготовкой программы, который имеет следующую структуру

```cpp
#include <iostream>
using namespace std;

// Комментарии, которые говорят, что именно нужно реализовать в этой программе

int main() {
    // Набор юнит-тестов для вашей реализации
    cout << "OK" << endl;
    return 0;
}
```

Вам нужно, **не меняя тело функции main**, реализовать то, что предложено в комментариях, так, чтобы ваша программа выводила на экран сообщение OK. Функция main содержит ряд юнит-тестов, которые проверяют правильность вашей реализации. Если эти тесты находят ошибку в вашей реализации, то вместо OK программа выведет подсказку о том, что именно работает неправильно.

Когда ваша программа начнёт выводить ```OK``` , можете отправлять свой файл на проверку. Ваша реализация будет тестироваться на другом, более полном наборе тестов. **То есть, если ваша программа выводит OK, то это не даёт гарантии, что ваша реализация будет принята тестирующей системой**. В случае неудачной посылки тестирующая система также выдаст вам подсказку о том, какая именно часть реализации работает неправильно.

На проверку можно отправлять весь файл с вашей реализацией: функцию *main* удалять из него не нужно.

***Часть 1***


В первой части вам надо реализовать класс *Rational*, который представляет собой рациональное число вида *p/q*, где *p* целое, а *q* натуральное. Он должен иметь следующий интерфейс:

```cpp
class Rational {
public:
  Rational();
  Rational(int numerator, int denominator);

  int Numerator() const;
  int Denominator() const;
};
```

Класс *Rational* должен гарантировать, что *p/q* — это несократимая дробь. Например, код

```cpp
Rational r(4, 6);
cout << r.Numerator() << '/' << r.Denominator();
```

должен выводить *«2/3»* — именно поэтому мы делаем *Rational* классом, а не структурой. Структура позволила бы нарушить этот инвариант:

```cpp
struct Rational {
    int numerator, denominator;
};

Rational r{2, 3};
r.numerator = 6; // Нарушен инвариант несократимости
```

Список требований, предъявляемых к реализации интерфейса класса *Rational*:

1. Конструктор по умолчанию должен создавать дробь с числителем *0* и знаменателем *1*.
2. При конструировании объека класса Rational с параметрами *p* и *q* должно выполняться сокращение дроби *p/q* (здесь вам может пригодиться решение задачи «Наибольший общий делитель»).
3. Если дробь *p/q* отрицательная, то объект *Rational(p, q)* должен иметь отрицательный числитель и положительный знаменатель.
4. Если дробь *p/q* положительная, то объект *Rational(p, q)* должен иметь положительные числитель и знаменатель (обратите внимание на случай *Rational(-2, -3)*).
5. Если числитель дроби равен нулю, то знаменатель должен быть равен *1*.

**Гарантируется, что ни в одном из тестов, на которых будет тестироваться ваша реализация, не будет знаменателя, равного нулю.**

Шаблон программы:

[rational_interface.cpp](https://d3c33hcgiwev3.cloudfront.net/_3eeecdad5734b31db47bc7272453f0ab_rational_interface.cpp?Expires=1622246400&Signature=er-xJuzM2nVebXpIiLOJ9H5u6iflVhepDeDI8Ho5ponbh1xmOkPN~43JuiU1ONU7~bd3TrbbYoy84-cqVosf7jHYxE2DwCK8HdRVlJMbCuXjGst3-Q352uCC4HgkjRxrhkj65UHVMxRsVOcPnbNGjxT4R2YVlrBEN3snNGrNNLY_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

***Часть 2***

Реализуйте для класса *Rational* операторы ==, + и - так, чтобы операции с дробями можно было записывать естественным образом. Например, следующий код должен быть валидным:

```cpp
const Rational r = Rational(1, 2) + Rational(1, 3) - Rational(1, 4);
if (r == Rational(7, 12)) {
  cout << "equal";
}
```

Шаблон программы:

[rational_eq_add_sub.cpp](https://d3c33hcgiwev3.cloudfront.net/_ce23ea19242276b22976595011c64042_rational_eq_add_sub.cpp?Expires=1622246400&Signature=KkHB9Ry5AxfBDoC24cb91YYtGs8BL4yXu6hkB28MuxYwShnFWXhhMSJ0BPqVyMRyXE5LGPhGc81vH5XwYrs0urhn8RqHw6vYZ74ZlhqkkSBIKirJj7ZmL0pVUNaBuIZDe-sTu92~Z1SF28fkMh~xm~djTjgb6By0O7pU~vfFbVM_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

***Часть 3***

Аналогично предыдущей части, реализуйте операторы * и /. Например, следующий код должен быть валидным:

```cpp
const Rational r = Rational(1, 2) * Rational(1, 3) / Rational(1, 4);
if (r == Rational(2, 3)) {
  cout << "equal";
}
```

**Гарантируется, что ни в одном из тестов, на которых будет тестироваться ваша реализация, не будет выполняться деление на ноль.**

Шаблон программы:

[rational_mult_div.cpp](https://d3c33hcgiwev3.cloudfront.net/_13549043214800e40c8444137d82a63b_rational_mult_div.cpp?Expires=1622246400&Signature=DuUk6X6OH-eVESHIMuwjqDlTRmkLXMrKXGWxXbg~QZT6TPYi6WalGhg20ehRfJvVKAC7jsIrYGwycZUNwPiUjDvQpeztoBIL1T~RyHAFl6thsSi2N8Bebkx9sm3-rYZZJOhy9dWxg6WH8hV-6lIYqNMD7e0WQbYKCkhN6yHLBzU_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

***Часть 4***
В этой части вам нужно реализовать операторы ввода и вывода для класса *Rational*. В результате у вас должен работать, например, такой код

```cpp
Rational r;
cin >> r;
cout << r;
```

Шаблон программы:

[rational_io.cpp](https://d3c33hcgiwev3.cloudfront.net/sRwCxEifTuKcAsRIn-7i7Q_1c5c8a0a0cc14383a77e2db4002fdeae_rational_io.cpp?Expires=1622246400&Signature=eVemPZKkTnT1fRfSGFGi6ls88vlvc3z~t~pta4SV8PZ-fd~sCJ04LbH0XUVfzcvbQOyfImkd0tFr3bKPRw8HIM1nliwCrettTy3oHZdrrfMynaceGJ93-V7oOaArCmyclzmsRknT7JfTUoC9-pTX5gjSS9Atw1ISMtYlfU5zc0w_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

##### Часть 5 #####
Наконец, вам нужно реализовать возможность использовать объекты класса *Rational* в качестве элементов контейнера *set* и ключей в контейнере *map*. Пример:

```cpp
set<Rational> rationals;
rationals.insert(Rational(1, 2));
rationals.insert(Rational(1, 3));
map<Rational, string> name;
name[Rational(1, 2)] = "одна вторая";
```

Шаблон программы:

[rational_map.cpp](https://d3c33hcgiwev3.cloudfront.net/_9d5919cda1901a8bc1955a69a74865b1_rational_map.cpp?Expires=1622246400&Signature=ehdPUVinIxUCAl~yerSOJTeQy7b-H-6p2AlrjRbi7CJaOzK6xoAZnYwGOcdnVwZaA9f2rGhwo6QfGvbKaowf9yWp58790SbDu39T4KIUAPMbfXP0v~kZIQgklpXsWT~9Wr71g7awmYF~OuIDCnvAXvd3hUK9jFJd3HBdKxpij4Y_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
