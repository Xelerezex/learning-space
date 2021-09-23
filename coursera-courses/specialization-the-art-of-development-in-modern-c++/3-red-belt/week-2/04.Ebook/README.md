## EBooks

*Вам даны задача и её решение — верное, но не удовлетворяющее заданным ограничениям на время работы.
Переработайте это решение и сдайте в систему.*

### Условие

Разработайте систему стимулирования чтения электронных книг. Для простоты будем считать, что книга всего одна,
но её одновременно читают много людей. Необходимо следить за прогрессом чтения у всех пользователей и
выводить мотивирующие уведомления. А именно, ваша программа должна обрабатывать следующие события:

-   **READ** ***user*** ***page*** — сохранить факт того, что пользователь под номером user дочитал книгу до страницы ***page***.
    Если ранее такой пользователь не встречался, необходимо его добавить. Гарантируется, что в рамках одного
    пользователя номера страниц в соответствующих ему событиях возрастают.

-   **CHEER** ***user*** — сообщить пользователю ***user***, какая доля существующих пользователей (не считая его самого)
    прочитала меньшую часть книги, чем он. Если этот пользователь на данный момент единственный, доля
    считается равной 1. Если для данного пользователя пока не было ни одного события **READ**, доля считается равной 0,
    *а сам пользователь не учитывается при вычислении долей для других пользователей* до тех пор, пока для него
    не случится событие **READ**.

### Формат входных данных

В первой строке вводится количество запросов *Q* — натуральное число, не превосходящее 10^6. В следующих *Q*
строках в соответствии с описанным выше форматом вводятся запросы. Гарантируется, что все вводимые числа
целые и положительные, при этом номера пользователей не превосходят 10^5, а номера страниц не превосходят 1000

### Формат выходных данных

Для каждого запроса **CHEER** ***user*** выведите единственное вещественное число от 0 до 1 — долю пользователей,
прочитавших меньше страниц, чем ***user***. Формат вывода этого числа должен быть в точности таким же,
как в опубликованном ниже медленном решении.

### Ограничения

4 секунды на выполнение всех запросов. Все описанные в условии гарантии действительно справедливы для всех тестов,
на которых будет запускаться ваша программа. Проверять корректность тестов не нужно.

### Example:

#### Input:

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

#### Output:

```commandline
0
1
0
0.5
0.5
1
0.5
```

**Комментарии к примеру**

Пользователь 5 не учитывается при вычислении долей, потому что для него не произошло ни одного события **READ**.

Пользователь 1 изначально был единственным, но в конце его обогнал 3-й, но не обогнал 2-й, поэтому он оказался
продуктивнее 50 % пользователей.

Пользователь 3 изначально обгонял только 2-го и потому получал долю 50 %, но в конце обогнал 1-го и получил долю 100 %.

### Правильное, но медленное решение

> [slow](https://d3c33hcgiwev3.cloudfront.net/7YdiJmS5EeiQ1RJfHSpJKg_ee2eec2064b911e8a488d1e3a26d9d2c_slow.cpp?Expires=1632528000&Signature=Jub9ZovQFrLXrCuER9aLWGQgaL-fokCJG9eCd7fja4gGI1vPX12dmVzEsHE7o6CAZKNPxUHCcjDU-PP9wlFemSNS574TDIFekx5TJyT~QM674co9AcYSqN0PnCeBondW3RaU~h6kksVLYiNYM1QQbsDrZ3QqSaPJFRUvyuAs4EU_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)


## Подсказки

Если задача вызывает непреодолимые трудности, вы можете воспользоваться подсказками. Они помогут быстрее
сдать задачу, но в итоге вы получите меньше пользы от процесса поиска решения.

Не нужно открывать все подсказки сразу. Используйте их последовательно.

> [ebook-1.pdf](https://d3c33hcgiwev3.cloudfront.net/4f6F9efeEei5Kg7DUflKxA_e26cfeb0e7de11e880463dc9adc4d9bc_ebook-1.pdf?Expires=1632528000&Signature=k9Tzk~7UJWulpMAF1aRqtuf4otrs-Iy~LkeskJDyeOCDwxpVw9VLMKP2J73wBePmZ~rJnbXguBybts9lOrWDxY3x8x-R0Ftis5HM8hYXOtwi~eUawmJowxta4D4pSujGZGlnkP3aqKMib4CWFfpg2YYvWL2JTyjzV9wqZCuYDKQ_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [ebook-2.pdf](https://d3c33hcgiwev3.cloudfront.net/4f6tLefeEeilxxL_ZeRz_A_e27478c0e7de11e89bf1032d5d05de4f_ebook-2.pdf?Expires=1632528000&Signature=QiyQPwn3-jh4uSaykk63SY4h-iO5Q-cuHuKLVCPU8jH6D1DGYu-IXtE-R-oICOg-9wRo~8z68FVRtruxTaeuXipPE11~OB3cFe2n-H0UoWX5NMflbxGXOJejb~f~zmaAmXXSnDV7Cm~U2nXKnkfpQLV2zq90g5P-IsqtTgnNLh4_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [ebook-3.pdf](https://d3c33hcgiwev3.cloudfront.net/4f9JAufeEeiaxBKyA9PBAg_e26f48a0e7de11e8b9ee51de5db3cbe5_ebook-3.pdf?Expires=1632528000&Signature=Ucd~3B-AxzNDRIZncXpch4gtYJK9NAg88Qp751wSaU0kYaew5MtyvUXb0uZ-zaUbfLaft9KRrF2EeO8orFjJe4IBkNSGLfYGk-37de-pI5jiPcKsX~0vDHJRXWErVUfknJ3dw755oIqHYKEs~SQJ1m9-2xVSQx2C-UuXUZpvlqg_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [ebook-4.pdf](https://d3c33hcgiwev3.cloudfront.net/4f9JAefeEeiaxBKyA9PBAg_e2727cf0e7de11e8ba36791774dc29a3_ebook-4.pdf?Expires=1632528000&Signature=CLbyEPLImzTBwuoIHhIizH7mCRHeZS2W8QvWm7-Z7-ExP-bCGTD743p4QQWXoJBnrmqwZZ8ippCEqgiTsD2Qi1tksX0xUhFZ8kBldudwTjEL9AuqhdtO7XRdWopuiWoMYN~IXp6uqDMXl3hL~8Oudu3Y7DIbi-J0S4bY8U0Q7zY_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [ebook-5.pdf](https://d3c33hcgiwev3.cloudfront.net/4gQEgefeEeiTKQ5ajE7PqA_e26ed370e7de11e88c94d51cedeec544_ebook-5.pdf?Expires=1632528000&Signature=gOHLL45qs4cB-DDxZL67ba2PhHZjgEhvHllXobfTEIxG5oKUqsnANo94gfya0npZTEE5jS9x1QJdmJwBh~SpX7mqyKlOU~Me8UyFMutYz7Z2UoGpNIyoPXYVFDdqjCK5Dn0F04gxHycWQCgDRUQgcxrufnK9chB5jlpuBP45XLY_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
