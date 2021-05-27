## Class Rational Exceptions

Вспомним класс *Rational*, который мы реализовали в задачах, посвящённых перегрузке операторов. Там специально говорилось, что в тестах объекты класса *Rational* никогда не создаются с нулевым знаменателем и никогда не выполняется деление на ноль. Настало время избавиться от этого ограничения и научиться обрабатывать нулевой знаменатель и деление на ноль. В этой задаче вам предстоит это сделать.

Поменяйте реализацию конструктора класса *Rational* так, чтобы он выбрасывал исключение [invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument), если знаменатель равен нулю. Кроме того, переделайте реализацию оператора деления для класса *Rational* так, чтобы он выбрасывал исключение [domain_error](https://en.cppreference.com/w/cpp/error/domain_error), если делитель равен нулю.

Напомним, что вам надо реализовать интерфейс

```cpp
class Rational {
public:
  Rational();
  Rational(int numerator, int denominator);

  int Numerator() const;
  int Denominator() const;
};
```

и оператор деления для класса Rational

```cpp
Rational operator / (const Rational & lhs, const Rational & rhs);
```

Так же, как и в задачах на перегрузку операторов, вам будет предложен файл с заготовкой кода. Функция *main* в этом файле содержит ряд юнит-тестов, которые позволят вам проверить свою реализацию. При проверке вашего решения оно будет тестироваться на более полном наборе тестов, так что успешное прохождение всех юнит-тестов не гарантирует, что ваша реализация будет зачтена.

Шаблон программы:
[rational_throw.cpp](https://d3c33hcgiwev3.cloudfront.net/_5e163726188df62884bc6a5e9777eb33_rational_throw.cpp?Expires=1622246400&Signature=k9IbOQa0MybEBTmHu~KYTXT1ohQiobcNRDyCMXgVJbKe5mDVCaEYZorHXHubNT0wky4bFAjS6xBNi9F91Z2vqQ6HYGSFB6Gp7rcaaHnC-hO7L34MWqY8mdujzfVvRusv~fvPYfeeKwO8YIdo7RkodmQ4pZTKbisMGMXUQyteDvU_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
