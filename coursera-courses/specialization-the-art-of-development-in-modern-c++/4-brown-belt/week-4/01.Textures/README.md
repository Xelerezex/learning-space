## Textures

На лекциях вы познакомились с умным указателем ```shared_ptr```, который обеспечивает совместное владение
объектом. В данной задаче вам нужно будет реализовать классы фигур, которые можно отрисовывать на изображении,
и которые совместно владеют заданной текстурой.

Среди доступных вам файлов вас в первую очередь будет интересовать файл **Common.h**. В нём приведён
интерфейс ```IShape```, который описывает фигуру. Существуют два вида фигур: прямоугольник и эллипс. Они
указаны в перечислении ```ShapeType```. Ваша задача реализовать функцию ```MakeShape```, которая создаёт
фигуру заданного вида.

Интерфейс ```IShape``` позволяет запрашивать и задавать ряд свойств фигуры: позицию, размер и текстуру.
Также он позволяет клонировать фигуру с помощью метода ```Clone()```. Это похоже на то, как если бы вы
выбрали в редакторе графики фигуру и нажали ```Ctrl+C``` и ```Ctrl+V```. Идея в том, что склонированная
фигура использует ту же самую текстуру, что и оригинал. Это удобно, т.к. в общем случае текстура может
занимать много памяти. Разумеется, в дальнейшем склонированной фигуре можно задать новую текстуру.

Объект текстуры должен быть удалён в тот момент, когда нет больше фигур, которые имеют данную текстуру. Это
может произойти при удалении фигуры, или при назначении фигуре другой текстуры.

Кроме того, интерфейс ```IShape``` позволяет отрисовать текущую фигуру на заданном изображении с помощью
метода ```Draw()```. Отрисовка происходит по следующим правилам:

<img src="https://github.com/Xelerezex/learning-space/blob/learning-space/coursera-courses/specialization-the-art-of-development-in-modern-c%2B%2B/4-brown-belt/week-4/01.Textures/Source/tree.png"/>

-   Из позиции и размера фигуры формируется её ограничивающий прямоугольник

-   Внутри ограничивающего прямоугольника формируется множество точек, принадлежащих фигуре - форма фигуры
    (если фигура это прямоугольник, то форма фигуры совпадает с ограничивающим прямоугольником)

-   Текстура накладывается на ограничивающий прямоугольник таким образом, чтобы их левый верхний угол совпадал

-   Заполняются пиксели изображения, попадающие внутрь формы фигуры

-   Пиксели, что находятся на пересечении формы фигуры и текстуры, заполняются пикселями текстуры (если
    текстура отсутствует, можно считать, что она нулевого размера)

-   Остальные пиксели заполняются заливкой по умолчанию - символом "." (точка)

-   Если какие-то пиксели выходят за границы изображения, они просто игнорируются

В качестве примера правильной отрисовки следует посмотреть тесты, вызываемые из функции ```main()``` в файле
```main.cpp```. В тестах создаётся канва (экземпляр класса ```Canvas```). Канва это по сути автоматизированный
редактор графики, который управляется через открытые методы. Например, метод ```AddShape()```
добавляет новую фигуру с помощью функции ```MakeShape()```, которую вам нужно реализовать. А метод
```DuplicateShape()``` клонирует существующую фигуру, вызывая метод ```Clone()```, который вам, опять же,
нужно будет реализовать. Таким образом, с помощью тестов можно будет проверить корректность своей реализации.
Однако будьте осторожны - как и в других заданиях, успешное прохождение открытых тестов есть необходимое, но
не достаточное условие корректности вашей реализации.  Своё решение опишите в файле ```Solution.cpp``` и
присылайте его на проверку.

### Замечание

Вычислить целочисленную форму эллипса можно по-разному, поэтому для определённости воспользуйтесь
предоставленной функцией ```IsPointInEllipse()```.

>   [Textures.h](https://d3c33hcgiwev3.cloudfront.net/8_rVg_3_EeiAgQrXx6bp4g_f45c0800fdff11e8baa633ec03f95dff_Textures.h?Expires=1649462400&Signature=OuA8RtUMO5R2QbXfgEiQDRYKFzoCMqKGupAO2D0tcoPB4UQxJhp39CZI07vfZ3Xa-8qMWpOQ6RAjgJKLAvMZEuOnriIHaEbASnPWvtUY1p3c0OXwIbrzhC6~0ArRU78olWh9o3eox9KAbTvUkOCZSowK6JWYqR7e42WW3Ndqoh4_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [Textures.cpp](https://d3c33hcgiwev3.cloudfront.net/8--ybP3_Eei5Kg7DUflKxA_f45d8ea0fdff11e890b3139b42242b91_Textures.cpp?Expires=1649462400&Signature=aYGqXVQeIlpZpjHvqC6XOV9Q1H87ToFCA8gh3FoH--a9~Pc~ISJ6hEsi5Mmnvq99tFbtFXmiA32l1DpSqcdmkSfDzo0htTHwVSQq8dc9rDb10hgmNiW2HhCObqVmzqisk8b~BsUi3WEoSk4OqvXSzch92tWXroqbZ0ZlkzdKZFk_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [main.cpp](https://d3c33hcgiwev3.cloudfront.net/8_Dqdf3_EeilxxL_ZeRz_A_f43c7210fdff11e8bb8e8370aeef7248_main.cpp?Expires=1649462400&Signature=K~SBiCPi8tJYOsh8Le-iWgwGlkRdtKmdTXcCarudjvdI~IQ64BoX77KfdaM79MZFczvHxxlR-2pQYSeEdaOQXaB3V0q6cRDAza~MA3oeUJFFsRQa~L7Mn2IUmqu7MEzhUglmUJ~JS9NuwXkcQnds7N6KKk~oGTY9JkoDtMz5V5A_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [Solution.cpp](https://d3c33hcgiwev3.cloudfront.net/QRC-OP4TEeiTKQ5ajE7PqA_416d8390fe1311e8a68b1b5a9f1726a7_Solution.cpp?Expires=1649462400&Signature=H62az06A~y30kqPWXvoQoDBNeWZOZU7VVjYf0osnf-Fp6pUOtJrv1v8zErbEe8LYUQD~X4FHnejxkOMPm~W5U7LXzgD2Vp7MbGF6XdXaiwgdAr60ncvElabBl~jieqqEN48SeCAxU65yi-OIratLDyIMkKGhxVsVS~49JPRa4KY_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [Common.h](https://d3c33hcgiwev3.cloudfront.net/J_Lg6ObkSSCy4Ojm5CkgVQ_3c01315f28bb429490a57ff2f1ec3cad_Common.h?Expires=1649462400&Signature=jwf~cNwE2iwgh70sYsaqxU4XLnOrs5QldvM~Qe0e16Yl7SwHux-VsKNYdPD2n7s9LoRdibAwkknOZxPxJkVjJEnC1RBxKPdKyBKb3iPC2Qms1icqeEdnOhXIkfZ4FF~JnXuo1g~3417davLFOK9cv1tRPMt-TIn5ZkGyTUjz1ms_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
