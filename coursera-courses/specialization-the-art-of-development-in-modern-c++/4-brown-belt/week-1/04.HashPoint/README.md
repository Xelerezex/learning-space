## Hash Point

Мы хотим научиться встраивать структуру ```Point3D``` в контейнер ```unordered_set<Point3D, Hasher>```.
Для этого вам нужно реализовать структуру ```Hasher``` и оператор сравнения:

```cpp
using CoordType = int;

struct Point3D
{
    CoordType x;
    CoordType y;
    CoordType z;

    bool operator==(const Point3D& other) const {
        // реализуйте оператор
    }
};

struct Hasher
{
  // реализуйте структуру
};
```

В своей реализации используйте стандартную хеш-функцию ```std::hash<CoordType>``` для хеширования
координат и комбинируйте полученные хеши с помощью полинома, как показано в лекции.

### Требования:

-   хеш-функция должна зависеть от всех координат точки

-   хеш-функция должна равномерно рассеивать точки в трёхмерном пространстве; это её свойство
проверяется тестом ```TestDistribution``` в заготовке решения.

### Заготовка решения

>   [hash_point.cpp](https://d3c33hcgiwev3.cloudfront.net/ODpzrvPNEei5Kg7DUflKxA_389208e0f3cd11e89aa295b2bbe8221e_hash_point.cpp?Expires=1644537600&Signature=Qw4crSJtzOuBJU-MaLhgSj8pEtSqNBLlXOS2dTOQA0yX0CIM~RCLLn8SXQI8GmIg9UfUSLT0HsRUIgGoDO32cmfCW0XZ9Hw3ueP5zgr-aHtHjSZ3gzslM3rij4cT-J-~BGsFnf-GfcNGYc8SLDew9N6Jy5PGE~p2SLkkfm~hkMI_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
