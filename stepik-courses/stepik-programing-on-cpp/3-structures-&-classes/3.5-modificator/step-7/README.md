

***Задание повышенной сложности***.

Определен следующий класс (он также приведен в комментарии в шаблоне кода):

```cpp
struct Cls {
    Cls(char c, double d, int i);
private:
    char c;
    double d;
    int i;
};
```

Как видно, все поля этого класса закрытые, ваша задача реализовать несколько функций, которые дают полный доступ к этим полям (см. шаблон кода), несмотря на то, что они закрытые.

***Внимание***: предполагаемое решение этого задания существенно опирается на Undefined Behaviour и является исключительно учебным, но полезно для лучшего понимания того, как работают модификаторы доступа. Решение было проверено на различных компиляторах (g++/clang++/icc/msvc), но мы настоятельно ***не рекомендуем*** использовать подобные трюки в боевом коде.

***Требования к реализации***: при решении этого задания вам разрешается заводить любые вспомогательные функции и классы, но не изменять определение класса Cls. Не нужно вводить или выводить что-либо, также не нужно определять функцию main.