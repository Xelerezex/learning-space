## Double dispatching

### Теория — статический и динамический тип указателя или ссылки на объект

Рассмотрим простой код

```cpp
struct Parent
{
    virtual string Name() const { return "Parent"; }
};

struct Child : Parent
{
    virtual string Name() const override { return "Child"; }
};

void Print(const Parent& object)
{
    cout << object.Name() << '\n';
}

int main()
{
    Print(Parent());
    Print(Child());
}
```

Если у вас спросить, какой тип имеет параметр ```object``` функции ```Print```, вы наверняка ответите
«```const Parent&```» и будете правы. А если мы спросим, на объект какого типа ссылается параметр
```object```, то правильным будет ответ: «Зависит от того, какой объект передали в функцию ```Print```».

Получается, с одной стороны, мы знаем, какой тип имеет параметер ```object```, но с другой стороны,
мы не можем точно сказать, на объект какого типа он ссылается. В этом и состоит разница между
статическим и динамическим типом ссылки (или указателя) на класс, у которого могут быть наследники.

Статический тип ссылки — это тип, известный на этапе компиляции. В нашем примере статический тип
параметра ```object``` — это ```const Parent&```.

Динамический тип ссылки — это тип объекта, на который она ссылается в данный момент времени.
Динамическим типом параметра ```object``` во время первого вызова функции ```Print``` будет
```const Parent```, во время второго вызова функции ```Print``` — ```const Child```.

### Теория — тип указателя this в классах-наследниках

Теперь давайте рассмотрим другой пример. Как вы думаете, что будет выведено на экран?

```cpp
struct Parent;
struct Child;

void PrintType(Parent*) { cout << "Parent\n"; }
void PrintType(Child*) { cout << "Child\n"; }

struct Parent
{
    virtual void Print() { PrintType(this); }
};

struct Child : Parent
{
};

int main()
{
    Child().Print();
}
```

Вариантов, на самом деле, всего два, и правильный — это «```Parent```». Несмотря на то, что мы создали
объект типа ```Child```, указатель ```this``` внутри методов класса ```Parent``` имеет тип
```Parent*```, а не ```Child*```, как могло бы показаться. И это логично, потому что

-   выбор, какая из двух функций ```PrintType``` будет вызвана из метода ```Parent::Print```,
    осуществляется на этапе компиляции; в этот момент компилятор наверняка знает только одно —
    что указатель ```this``` будет указывать на объект класса ```Parent```

-   виртуальными (то есть зависящими от динамического типа) в C++ могут быть только методы, а
    ```this``` — это лишь указатель.

Наконец, рассмотрим ещё один пример и снова зададимся вопросом, что он выведет:

```cpp
struct Parent;
struct Child;

void PrintType(Parent*) { cout << "Parent\n"; }
void PrintType(Child*) { cout << "Child\n"; }

struct Parent
{
    virtual void Print() { PrintType(this); }
};

strut Child : Parent
{
    void Print() override { PrintType(this); }
};

int main()
{
    Child().Print();
}
```

Мы переопределили метод ```Print``` в классе ```Child```, оставив у него точь-в-точь такую же
реализацию, какая была в ```Parent::Print```. Но кое-что изменилось — тип указателя ```this```.
Внутри метода ```Child::Print``` он имеет тип ```Child*```. Причина та же — когда компилятор
обрабатывает метод ```Child::Print```, он знает, что ```this``` точно будет указывать на объект
класса ```Child```.

Итак, главный вывод — ```this``` всегда имеет тип указателя на тот класс, в методе которого он
используется.

### Условие задачи

Из лекций мы узнали, что ```this``` всегда указывает на текущий объект класса, а также, что он
является неявным параметром всех его методов. Кроме того, мы только что познакомились с понятиями
статического и динамического типов ссылки (или указателя). В этой задаче мы объединим эти знания,
чтобы реализовать так называемую двойную диспетчеризацию — мы напишем функцию, которая ведёт себя
по-разному в зависимости от динамических типов двух объектов, которые в неё переданы.

Представим, что мы пишем движок для классической компьютерной стратегии: игроки строят города,
формируют армию, а потом сражаются друг с другом. В нашей игре есть несколько объектов:

-   юниты — это солдаты, рабочие, кавалеристы и т.д.

-   здания — фабрики, заводы, казармы и т.д.

-   башни и стены — защитные сооружения для обороны своего города

Мы работаем над функциональностью размещения новых объектов на игровой карте. Допустим, мы хотим
построить новое здание. Мы начинаем искать на карте место, где его можно разместить, а графический
интерфейс игры нам в этом помогает. Здание можно построить в том месте карты, где нет других объектов.
Если в текущей позиции здание пересекается с каким-то из объектов, то интерфейс рисует наше здание
красным цветом, сообщая, что здесь его построить нельзя.

При этом юниты представляются точкой на плоскости, здания — прямоугольником, башни — кругом, а стены
— отрезком. Кроме того, для каждого игрового объекта в нашем движке заведён отдельный класс, который
наследуется от абстрактного класса ```GameObject```:

```cpp
class Unit;
class Building;
class Tower;
class Fence;

struct GameObject {
    virtual ~GameObject() = default;

    virtual bool Collide(const GameObject& that) const = 0;
    virtual bool CollideWith(const Unit& that) const = 0;
    virtual bool CollideWith(const Building& that) const = 0;
    virtual bool CollideWith(const Tower& that) const = 0;
    virtual bool CollideWith(const Fence& that) const = 0;
};
```

Наша задача — реализовать функцию
```bool Collide(const GameObject& first, const GameObject& second)```, которая проверяет пересекаются
ли два игровых объекта, то есть имеют ли они хотя бы одну общую точку.

Вам даны:

-   файл **game_object.h**, содержащий интерфейс ```GameObject``` и объявление функции ```Collide```

-   файлы **geo2d.h/cpp**, содержащие библиотеку для работы с геометрическими фигурами на плоскости;
    библиотека состоит из классов ```Point```, ```Rectangle```, ```Circle``` и ```Segment``` и набора
    функций ```Collide```, которые умеют определять пересечение для каждой пары фигур (занимательный
    факт — все функции реализованы в целых числах, без применения вычислений в типе ```double```)

-   файл **collide.cpp**, содержащий заготовку решения, а также юнит-тест, эмулирующий размещение
    нового объекта на игровой карте

Пришлите в тестирующую систему файл **collide.cpp**, который будет:

-   подключать **game_object.h**

-   содержать реализации классов ```Unit```, ```Building```, ```Tower``` и ```Fence``` (все они
    должны наследоваться от ```GameObject``` и реализовывать его интерфейс)

-   содержать реализацию функции
    ```bool Collide(const GameObject& first, const GameObject& second)```, которая возвращает
    ```true```, если объекты ```first``` и ```second``` имеют на плоскости хотя бы одну общую
    точку, и ```false``` в противном случае.

### Замечание

Один из способов реализовать функцию ```Collide``` — использовать ```dynamic_cast```. Мы не освещали
его в лекциях. Кроме того, этот способ приводит к появлению развесистого кода, подверженного
возникновению ошибок. Мы хотим, чтобы в этой задаче вы хорошенько разобрались с понятиями
статического и динамического типа, а также поработали с указателем ```this```. Поэтому мы будем
компилировать ваши решения с флагом ```-fno-rtti```, который будет приводить к ошибкам компиляции
в случае использования ```dynamic_cast```.

>   [geo2d.h](https://d3c33hcgiwev3.cloudfront.net/7HNY-_YyEeiAgQrXx6bp4g_ed8d53a0f63211e894821fafea8f4186_geo2d.h?Expires=1646179200&Signature=T~KXZR7PWwLeoahD2czCeV3Q7HySL5-L~6wXJ6mDBGg7sQyQ9eust4AD5BAPhih9OPScszZpVfKT98uBr05yPlJa5Z4BAAMxjSwVJUodmg~dMl0En-AJOfcyib8oj6cs6iq7ULh8m7NYY8Nq0KyyBLCLdABFvHch3mIPtYCZIyA_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [geo2d.cpp](https://d3c33hcgiwev3.cloudfront.net/KWzIRvYzEeiTKQ5ajE7PqA_29b2f880f63311e88f4a15face05d481_geo2d.cpp?Expires=1646179200&Signature=O8lvveGCh61mQnwYvhKgY8TdzM8K5lHXtIeRSHkr944-zBNNkb9ovXwLnENqao8WHO1Ed7HWZEVT2ZgmT6v96fbEPHK77nZGaKyWnXSioMOzTCV8Ye7ZOlANxXpvKHZCUb19blBwMD44lDp7bHa0IOMVR6Uzv2~v2PHRkgx-goc_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [game_object.h](https://d3c33hcgiwev3.cloudfront.net/PfGe4fYzEeiTKQ5ajE7PqA_3e3277e0f63311e882cf5b014df25ce8_game_object.h?Expires=1646179200&Signature=RzT5ZMNNnhwb5xP5u~oXIk24bzrXQlqJzDEdTGRiMT-GENie6qSkFenISFs6YbYiiWoe3-AuvjcQMTEGyzJpZ6vCaLmsImOG63tdVff5rQ2EIV2HaJligC16-tpt7EtXfc1Lwxh2i6YvTAV7pWc1-j6AnWoebcWFNwKLkk36JC8_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [collide.cpp](https://d3c33hcgiwev3.cloudfront.net/UPnD7QN6EemU7w7-EFnPcg_515550f0037a11e9a0067f9a9861604c_collide.cpp?Expires=1646179200&Signature=VDD23XlT3kBo7E0jTdLR9LIZv~~CGa8rGkbFLcxuwHD6-f-PiixN29KCk6sOyxY06goqrSW6lqD8~iyQlQgeo7XWcT3HBqaxuGghgFOK43WDDHoYxcc16dk9VWOG0~qTCadW-BJ0eKUWg-E1JvKyNo6gxx51~gEtXScMOVrYj7E_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

### Подсказки

Для этой задачи есть набор подсказок, которые должны помочь вам с решением. Если вам не удаётся
решить задачу и вы чувствуете, что у вас кончились идеи, вы можете ими воспользоваться. Но сначала
обязательно попробуйте решить задачу без подсказок.

>   [Подсказка 1.pdf](https://d3c33hcgiwev3.cloudfront.net/oET5nfYzEei5Kg7DUflKxA_a095b190f63311e8a5c7eba363433e77__________-1.pdf?Expires=1646179200&Signature=CbfXrg~vSiXeaPxTC4PklTmYZk~~C5McC7OiTWs-bA-LeCFGLcnBD7hIf-irThaWTwuSmjVCuiOZ1B9ey1yiLip2EYh5e4q1CCVuY7GoYWuM80wuyAAovJY3D2kxKuNDRO6VnWTqIZbBY1MS8AB3Zfnbp5f7Eaop1Ugr2A3abq4_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [Подсказка 2.pdf](https://d3c33hcgiwev3.cloudfront.net/oEUhRvYzEeiTKQ5ajE7PqA_a0cd8a70f63311e89aa353e40edb32e4__________-2.pdf?Expires=1646179200&Signature=PRQxZFlyBTUCW8kd0BU1zEgL8iMYwbpmfi3B8ZPtPNCL88767klYXtqX3Y-2eqa9l40-M3CRN7fGJH99mGj69L5-UU1Jmk7J~hoTVLHGJIkwdh~RuOB8TE2hhNDx-faaKQRhFQ4kPjI1tl0gu-UQSUNajWMRNWf7Juzs9JD4AJM_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [Подсказка 3.pdf](https://d3c33hcgiwev3.cloudfront.net/oEQ2kPYzEeilxxL_ZeRz_A_a0cf5f30f63311e8b293a14f8879aaef__________-3.pdf?Expires=1646179200&Signature=EElVqhy1G-vYtDgRcnWxu~i4JkT6mNzUqjI675e2CKVcnHHfp3FkOHzgjfLyR0TBZ1-y9CrF~kNtDggKYHHj1gAvM5QnHRpuuJBXcGOH7cY4arpEC2WGuRatwMbJFE4hYKEAnEu4CUTEMklq-WCdZH2qIn1jLJNi86GxxaUaDDA_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [Подсказка 4.pdf](https://d3c33hcgiwev3.cloudfront.net/oESE3vYzEeiaxBKyA9PBAg_a0d21e50f63311e89aa295b2bbe8221e__________-4.pdf?Expires=1646179200&Signature=UqPSU5vLbKOVB3pq7RiDVjTy7CWQSwoWxxDXzTzMlCJA6Ngi-rS2f2e-f-g0etb8Lgbja3L9ZKv6-NXWrzqZBBFhjgZdplWEDsMY4lXnulVib2lBR~pyoU0Tw1Xcq7JqppkieAgvkL~DjUVT8Jf2ioC3RBQz0mqoUFGxllfw0a0_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [Подсказка 5.pdf](https://d3c33hcgiwev3.cloudfront.net/oEbOofYzEeilxxL_ZeRz_A_a0f313d0f63311e882cf5b014df25ce8__________-5.pdf?Expires=1646179200&Signature=Fw6gPNL7h4zGArQF6Lh4LQ1KAPT4KVweQueWeuQdRWvnzFzBCWrNSpIsNiKby3w5hhAFT69M4hrc3K0bjGbUhJxeTwIwdIfsKIlhSAKOtVoODDZAYqBJY3vYuRMoahHmMVygq~-j4n-n8A76pyCZJ8TkcCB-iMo36iHK4B0W8yY_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
