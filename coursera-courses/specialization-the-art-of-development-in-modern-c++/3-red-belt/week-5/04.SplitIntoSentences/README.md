## Split Into Sentences

Дан вектор токенов. Напишите функцию, разбивающую токены на предложения:

```cpp
template <typename Token>
vector<Sentence<Token>> SplitIntoSentences(vector<Token> tokens);
```

Token — шаблонный тип, про который известно лишь то, что он имеет константный метод
```IsEndSentencePunctuation```, возвращающий true, если токен является знаком пунктуации,
заканчивающим предложение, и false в противном случае. **Объекты этого типа запрещено копировать**.
При наличии копирования этих объектов вы получите ошибку компиляции.

Sentence — синоним для типа ```vector```, объявленный следующим образом:

```cpp
// Объявляем Sentence<Token> для произвольного типа Token
// синонимом vector<Token>.
// Благодаря этому в качестве возвращаемого значения
// функции можно указать не малопонятный вектор векторов,
// а вектор предложений — vector<Sentence<Token>>.
template <typename Token>
using Sentence = vector<Token>;
```


Предложением считается последовательность токенов, заканчивающаяся подряд идущими токенами,
являющимися знаками пунктуации конца предложения. Иными словами, любое предложение должно состоять
из двух частей:

-    токены, для которых ```IsEndSentencePunctuation``` возвращает **false** (такие токены обязаны
     присутствовать в предложении за исключением, возможно, первого предложения);

-    токены, для которых ```IsEndSentencePunctuation``` возвращает **true** (такие токены обязаны
     присутствовать в предложении за исключением, возможно, последнего предложения).

### Ограничения

Максимальное количество токенов — 10^6. Время выполнения одного вызова функции ограничено 1 секундой.

### Файл с заготовкой решения

> [split_into_sentences.cpp](https://d3c33hcgiwev3.cloudfront.net/OMX_bWWhEeiUPhLykNFyig_38f3290065a111e894bd27e6c7a09e51_split_into_sentences.cpp?Expires=1637280000&Signature=ghnVPp0~iyR41IdOppPzC9fr~pggFKXawuTo-jyHF0uc4XTRIzo6PHkzq-PzsQI9OxyC-~gxAro5WsbL4vzEvH2UmjfNrppzobTFsl~0a2iyGJ-wcrshtpDUt8aCLYw8weiIYZ2yVnTuK~YraequcVtsSoCvqsdKjsCgG3nxXTg_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
