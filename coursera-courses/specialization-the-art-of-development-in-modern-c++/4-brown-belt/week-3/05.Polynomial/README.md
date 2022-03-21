## Polynomial

В лекциях мы наглядно продемонстрировали, что константность ограничивает набор операций, которые можно выполнять с
объектом, защищая его от нежелательного изменения. Однако возможности константности ограничены, и в некоторых
случаях она не позволяет достичь желаемого эффекта. В таких ситуациях на помощь приходит система типов, которая
позволяет создавать классы с требуемыми свойствами. Мы рассмотрим такую ситуацию в этой задаче.

Вам дана реализация шаблона ```Polynomial```, который представляет собой многочлен от одной переменной. Тип
```T``` этого шаблона задаёт тип коэффициентов и переменной. То есть ```Polynomial<int>``` -- это многочлен с
целочисленными коэффициентами от целочисленной переменной, ```Polynomial<double>``` -- это многочлен с вещественными
коэффициентами от вещественной переменной. Рассмотрим интерфейс класса ```Polynomial<T>```:

```cpp
template<typename T>
class Polynomial
{
    private:
      ...
    public:
        // Принимает вектор коэффициентов (коэффициенты задаются от младшего к старшим)
        // Например, Polynomial({10, 2, 3, 4}) создаёт многочлен 4*x^3 + 3*x^2 + 2*x + 10
        Polynomial(vector<T> coeffs);

        // Создаёт многочлен, все коэффициенты которого равны нулю
        Polynomial();

        // Аналогичен конструктору от вектора, но принимает пару итераторов
        template<typename Iterator>
        Polynomial(Iterator first, Iterator last);

        // Операторы проверки на равенство и неравенство. Два многочлена равны тогда и только тогда,
        // когда их соответствующие коэффициенты попарно равны
        bool operator ==(const Polynomial& other) const;
        bool operator !=(const Polynomial& other) const;

        // Возвращает степень многочлена -- максимальную степень, коэффициент при которой не равен нулю.
        // Например, степень многочлена 2*x равна 1, степень многочлена 4*x^5 + x^3 - 10 равна 5,
        // степень многочлена 5 равна нулю.
        // Метод работает за O(1)
        int Degree() const;

        Polynomial& operator +=(const Polynomial& r);
        Polynomial& operator -=(const Polynomial& r);

        // Возвращает значение коэффициента при заданной степени.
        // Если переданное значение больше степени многочлена, метод возвращает 0
        T operator [](size_t degree) const;
        // Вычисляет значение многочлена в точке с переданным значением
        T operator ()(const T& x) const;

        using const_iterator = typename std::vector<T>::const_iterator;

        // Итераторы на коэффициенты многочлена
        const_iterator begin() const;
        const_iterator end() const;
};
```

В приведённой выше реализации есть только одна возможность задать значения коэффициентов многочлена — передать их
в конструктор. Однако на практике может оказаться полезной возможность задавать коэффициенты по одному (эта
возможность особенно полезна для сильно разреженных полиномов):

```cpp
Polynomial<int> p;
p[1] = 5;
p[24] = -8;
p[61] = 12;
p[314] = 272;
```

Ваша задача -- добавить эту возможность, а именно реализовать неконстантный ```operator[]``` для шаблона
```Polynomial```, который

-   будет позволять задавать значение коэффициента заданной степени (как в примере выше)

-   будет позволять читать значение коэффициента заданной степени (то есть должен работать код ```int cv = p[4];```)

-   будет работать за O(1) в случае, если не меняется степень многочлена

-   не будет менять степень многочлена, если запись не была произведена

Последнее требование можно выразить вот таким тестом:

```cpp
Polynomial<int> p;
p[2] = 1;
ASSERT_EQUAL(p.Degree(), 2);
int x = p[5];
ASSERT_EQUAL(x, 0);
ASSERT_EQUAL(p.Degree(), 2); // Мы ничего не записали в p[5], поэтому степень многочлена не изменилась
```

См. также юнит-тесты в заготовке решения

На проверку пришлите cpp-файл с полной реализацией шаблона ```Polynomial```.

### Заготовка решения

>   [polynomial](https://d3c33hcgiwev3.cloudfront.net/pHlHg6-6Eem5YwqUxVF09g_4d54c31e13e64b4db9b153d0a24b8182_polynomial.cpp?Expires=1647993600&Signature=EEKfkB~jVbBNDR4usF7TI6uWHhgE9M76Vc2U3wL7y3He9mZYDwIg0kEWogyE5pLAtOt8hbcv~~Sp5IurPlUxE4sO2OW39iNkLWvEn49XL61ZWJGSzWedITKa3CHpIyPte2nVUp86wo8~IBARYGbzcZ45HVzXTyq4dWW9rFjGvC0_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

### Подсказки

Для этой задачи есть набор подсказок, которые должны помочь вам с решением. Если вам не удаётся решить задачу и
вы чувствуете, что у вас кончились идеи, вы можете ими воспользоваться. Но сначала обязательно попробуйте решить
задачу без подсказок.

>   [Подсказка 1.pdf](https://d3c33hcgiwev3.cloudfront.net/As0qMPZAEeiTKQ5ajE7PqA_03194e10f64011e882cf5b014df25ce8__________-1.pdf?Expires=1647993600&Signature=hmAM7D4DXOBXKDPVJJRlZIDa8KSLFj8cT~tBkLgeuiyolNgIIjr-iiTVIT5UTZ4Wjwjfzyxzz27gyiH-rkobmQzSLmChEQ7ctk24CxtbYqr~jQlPOISxEtiP2kpYOpSICsD5iX1atD5jNMvgUzEojC2qBqs25gfLeJl-3vLMll8_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [Подсказка 2.pdf](https://d3c33hcgiwev3.cloudfront.net/AszcWPZAEeilxxL_ZeRz_A_03606930f64011e8a0e62f417d2d6100__________-2.pdf?Expires=1647993600&Signature=Zh54lPQ-hwsTv~XMgDLfJ5JljN7FQfyYZLl~sv68xA8yyaQjQNgBptYLN4AlyVwTkf5mca8pacSKpbtqAQRKaTItCWG4xj9q1qf72tBU968-OkbPAMAWXVkCgq8a5J2RvyH5bwH9oEKpdVUxVwTf1MXwJn472FbdRs3XGThMkFk_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [Подсказка 3.pdf](https://d3c33hcgiwev3.cloudfront.net/As1RQvZAEeiAgQrXx6bp4g_03617aa0f64011e8bbdf2f9b99305df4__________-3.pdf?Expires=1647993600&Signature=Ov96~iRg5o4sqdfQeZ6qYn1cW0BRfJ-zaf0fKN74Zce5Z0dvmgwrkfnUXwaHQaTXekwHObOi9n8N9NYcPz0i9-XKE2pmE2XdOZecvbxjl0wQxrmeNA6FJD42vtyBayoTptAM28Ybt6PgEvK2vuXA-PgxoACMfmfWQQ51xiA4bxY_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [Подсказка 4.pdf](https://d3c33hcgiwev3.cloudfront.net/AtA3c_ZAEeiAgQrXx6bp4g_0387c750f64011e88717b75766913400__________-4.pdf?Expires=1647993600&Signature=SWx2~E~ZdoyW95hZOn9BBPQlQ9AGGirLQ0F-lqdqZ34N-oAEKjCMNOscV3bhGQQGDt3FZQXWsc4t8ASVpMVU6WL43NAkxODYmXZsAvEuMDbcCW08Yqs-VkfvWBSYb9uuP8yZBQ1GLR~N2P9OUNjNaa~HUS7UUctLwJGA3r5pU0k_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [Подсказка 5.pdf](https://d3c33hcgiwev3.cloudfront.net/As0qMfZAEeiAgQrXx6bp4g_03792150f64011e8842eedff8ee7b80d__________-5.pdf?Expires=1647993600&Signature=bWGUm1py5zZXTuhzFNx54HVi8uIce-7KCtjr-zIG7HYLU~LmapR8LIDmw-j68WxbYiYPfzAODQrVupJ1Ve4y8sxScDDH~wd7oR3MCqgz1qk3f4MMmbnK8mtTvLDN7SyZBLR2sCCTLSz-HI12HeOBC0USbqJQh6~X9CRUbyT5L9c_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [Подсказка 6.pdf](https://d3c33hcgiwev3.cloudfront.net/As7_IPZAEei5Kg7DUflKxA_03bf7920f64011e8842eedff8ee7b80d__________-6.pdf?Expires=1647993600&Signature=Ps6aP5izZFfSxuAS4YxNQbd3D17KntLC5M6V8lVSeidm54MTH2yWBU~SRtBqmCPWzra83A84QDBb6daMSQap6JhF4E2syZt9oBN7O3-thO9tj~yaQ9Eh45hK35tEqpYk3MM97FKhVemBLK7WUdKRcuh8fbQf732CQEd3Xo10cSA_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
