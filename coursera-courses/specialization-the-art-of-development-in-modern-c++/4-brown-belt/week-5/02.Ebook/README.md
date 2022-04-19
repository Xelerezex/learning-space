## Ebook

*Вам даны задача и её решение — верное, но не удовлетворяющее заданным ограничениям на время работы.
Переработайте это решение и сдайте в систему.*

### Условие

Разработайте систему стимулирования чтения электронных книг. Для простоты будем считать, что книга всего одна,
но её одновременно читают много людей. Необходимо следить за прогрессом чтения у всех пользователей и
выводить мотивирующие уведомления. А именно, ваша программа должна обрабатывать следующие события:

-   **READ** ***userpage*** — сохранить факт того, что пользователь под номером ```user``` дочитал книгу до
    страницы ```page```. Если ранее такой пользователь не встречался, необходимо его добавить. Гарантируется,
    что в рамках одного пользователя номера страниц в соответствующих ему событиях возрастают.

-   **CHEER** ***user*** — сообщить пользователю ```user```, какая доля существующих пользователей
    (не считая его самого) прочитала меньшую часть книги, чем он. Если этот пользователь на данный момент
    единственный, доля считается равной ```1```. Если для данного пользователя пока не было ни одного события
    **READ**, доля считается равной ```0```, а сам пользователь не учитывается при вычислении долей для
    других пользователей до тех пор, пока для него не случится событие **READ**.

### Формат входных данных

В первой строке вводится количество запросов ```Q``` — натуральное число, не превосходящее ```10^6```. В
следующих ```Q``` строках в соответствии с описанным выше форматом вводятся запросы. Гарантируется, что
все вводимые числа целые и положительные, при этом номера пользователей не превосходят ```10^5```, а номера
страниц не превосходят ```1000```.

### Формат выходных данных

Для каждого запроса **CHEER** ***user*** выведите единственное вещественное число от ```0``` до ```1``` — долю
пользователей, прочитавших меньше страниц, чем ```user```. Формат вывода этого числа должен быть в точности
таким же, как в опубликованном ниже медленном решении.

### Ограничения

4 секунды на выполнение всех запросов. Все описанные в условии гарантии действительно справедливы для
всех тестов, на которых будет запускаться ваша программа. Проверять корректность тестов не нужно.

### Пример

#### Ввод

```commandline
12
CHEER 5
READ 1 10
CHEER 1
READ 2 5
READ 3 7
CHEER 2
CHEER 3
READ 3 10
CHEER 3
READ 3 11
CHEER 3
CHEER 1
```

#### Вывод

```commandline
0
1
0
0.5
0.5
1
0.5
```

### Комментарии к примеру

Пользователь ```5``` не учитывается при вычислении долей, потому что для него не произошло ни одного события
**READ**.

Пользователь ```1``` изначально был единственным, но в конце его обогнал ```3-й```, но не обогнал ```2-й```,
поэтому он оказался продуктивнее ```50 %``` пользователей.

Пользователь ```3``` изначально обгонял только ```2-го``` и потому получал долю ```50 %```, но в конце
обогнал ```1-го``` и получил долю ```100 %```.

### Правильное, но медленное решение

>   [slow.cpp](https://d3c33hcgiwev3.cloudfront.net/7YdiJmS5EeiQ1RJfHSpJKg_ee2eec2064b911e8a488d1e3a26d9d2c_slow.cpp?Expires=1650499200&Signature=co-wJ7FYVGwQkOKtMGFeU8w1MFzzntlT9dhYa6QlMKd-IpsCMPx6JB8SOypbi4H5mSEOFimUr-B~3P-s63fKFSu4ZgBdAZurC7c~-LR9gZRYIHOssBIpn3Dp07A1PyYG3p6iqe5sDEt07mP7FK16~XvT5kadiaYl-nW2G42ITnQ_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

### Подсказки

Если задача вызывает непреодолимые трудности, вы можете воспользоваться подсказками. Они помогут быстрее
сдать задачу, но в итоге вы получите меньше пользы от процесса поиска решения.

Не нужно открывать все подсказки сразу. Используйте их последовательно.

>   [Подсказка-1.pdf](https://d3c33hcgiwev3.cloudfront.net/4f6F9efeEei5Kg7DUflKxA_e26cfeb0e7de11e880463dc9adc4d9bc_ebook-1.pdf?Expires=1650499200&Signature=YI73x9APtew6rziu1Idv3vgNyfp-Opz7ADZSd0E62riLqMetLlNmTaf5HPG8lX4krVMZssXE8dcU14GH2cBZ2o77gNPQWwfBNitgJo0LOHu4dSd-i7qNmZILm2rOTHS9zTbY32kSY5T-za2YN2vVUlBcKDqExYL~WFIv2P8~vUM_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [Подсказка-2.pdf](https://d3c33hcgiwev3.cloudfront.net/4f6tLefeEeilxxL_ZeRz_A_e27478c0e7de11e89bf1032d5d05de4f_ebook-2.pdf?Expires=1650499200&Signature=BKCCELIzohbNMeXyXK-x8xfkeDNVcwnEL6N3znC5JAyPci-Ic5MCd0mFTfJJncmb9et-gSptCCoy1pjL5IIjr2jC8bA5wbaDxMrZ4z5dvRbPtbtwiaDO~oatsCQLZuYIDcCK55IMXXvPPJY5vBeTx2Uy2bNzKWlziqfFvxYkeY0_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [Подсказка-3.pdf](https://d3c33hcgiwev3.cloudfront.net/4f9JAufeEeiaxBKyA9PBAg_e26f48a0e7de11e8b9ee51de5db3cbe5_ebook-3.pdf?Expires=1650499200&Signature=hqZ9WsnIJNEV33ZBB4XxEBJm5E1B9e3EW-EWhDdTH2~BeZsBF5Ig3lomvuljDMMixBhQz~UJEMKpEwLbnqEyS9ljRcWtBQSC-bcHRRDnURkbjPVbuwK-p-Rm2aocY9WuuDEhBcUIhLUGmDvNhO7wqKy~8L8-Xi2fCNjC8Qxyx~4_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [Подсказка-4.pdf](https://d3c33hcgiwev3.cloudfront.net/4f9JAefeEeiaxBKyA9PBAg_e2727cf0e7de11e8ba36791774dc29a3_ebook-4.pdf?Expires=1650499200&Signature=L9lbTXGjTpSaEEke4njfDSn4u0f1a-6GbvgcHN3sRye3GiIieXXMM3yNspGHcp8cAOwOQqakfY6kaR5GEyxR-J33FeA3mnmHLIj5o6HGCF4588ChpfxXgJxzuiT1tjOtlBe62Cohw-OvQTPbpFc~BcPZ3DjJK9MbQjkfJeHoEJw_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [Подсказка-5.pdf](https://d3c33hcgiwev3.cloudfront.net/4gQEgefeEeiTKQ5ajE7PqA_e26ed370e7de11e88c94d51cedeec544_ebook-5.pdf?Expires=1650499200&Signature=gC2bN0E8aBEralvOnON3JV2BRqPeJfTlQzWQ0WBcBwg0opoNfsb26q0BgVHlGinxyoTuQFu6mdYcwlTStaSAbckJdXAlWZBUYHKTxtMb5zeAFX9iqpWbOKZldbx2o4gEGbS~Ff6P23Y4ShmW2Qt03foJFr-cRzbJ~rO3~n0VDzU_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
