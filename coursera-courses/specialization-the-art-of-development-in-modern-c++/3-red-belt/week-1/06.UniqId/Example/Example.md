```c++
#define UNIQ_ID_IMPL_2(lineno) _a_local_var_##lineno
#define UNIQ_ID_IMPL(lineno) UNIQ_ID_IMPL_2(lineno)
#define UNIQ_ID UNIQ_ID_IMPL(__LINE__)
```

Мы хотим, чтобы объявления

```c++
 int UNIQ_ID = 5;
 string UNIQ_ID = "hello!";
```

порождали уникальные имена переменных.
Сделать это можно, например, добавив к имени каждой переменной номер строки, на которой она объявлена:

```c++
 int _a_local_var_1 = 5;
 string _a_local_var_2 = "hello!";
```

Для этого используем макрос \__LINE\__ и конкатенацию с помощью ##.  Однако, просто написать

```c++
#define UNIQ_ID_IMPL(lineno) _a_local_var_##lineno
#define UNIQ_ID UNIQ_ID_IMPL(__LINE__)
```

мы не можем, так как \__LINE\__ в этом случае не развернётся в номер строки. Поэтому мы используем вспомогательный макрос UNIQ_ID_IMPL,
как в таких случаях и поступают (https://www.iar.com/support/resources/articles/advanced-preprocessor-tips-and-tricks/).

Рассмотрим работу макросов в порядке их развёртывания:

-    макрос UNIQ_ID просто передаёт ___LINE__ как параметр макросу UNIQ_ID_IMPL;

-    макрос UNIQ_ID_IMPL разворачивает ___LINE__ и передаёт его как параметр макросу UNIQ_ID_IMPL_2;

-    макрос UNIQ_ID_IMPL_2 склеивает _a_local_var_ с номером строки.
