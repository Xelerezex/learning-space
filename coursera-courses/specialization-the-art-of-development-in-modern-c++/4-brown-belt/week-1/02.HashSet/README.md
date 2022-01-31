## HashSet

Теперь, когда вы знаете, как unordered-контейнеры устроены внутри,
вам предлагается самостоятельно реализовать упрощённую версию хеш-таблицы.
Реализуйте шаблон HashSet:

```cpp
template <typename Type, typename Hasher>
class HashSet {
public:
    using BucketList = forward_list<Type>;

public:
    explicit HashSet(
        size_t num_buckets,
        const Hasher& hasher = {}
    );

    void Add(const Type& value);
    bool Has(const Type& value) const ;
    void Erase(const Type& value);
    const BucketList& GetBucket(const Type& value) const;
};
```


Требования:

-   В любой момент времени в вашей хеш-таблице должно быть ровно ```num_buckets```
    корзин. Рехеширование выполнять не нужно.

-   Метод ```Add``` не должен менять содержимое таблицы, если элемент, равный данному,
    уже есть в таблице.

-   Метод ```Has``` должен возвращать ```true``` тогда и только тогда, когда элемент,
    равный данному, есть в таблице.

-   Метод ```Erase``` должен стирать элемент, равный данному, из таблицы, если он там
    есть, в противном случае он не должен менять содержимое таблицы.

-   Метод ```GetBucket``` должен возвращать ссылку на бакет, который содержал бы
    данный элемент, вне зависимости от того, есть он в таблице или нет.

**Заготовка решения задачи**

> [hash_set.cpp](https://d3c33hcgiwev3.cloudfront.net/GmjSH_4XEeiixgqCUDoEfA_1acf8270fe1711e889863f69802a45e1_hash_set.cpp?Expires=1643587200&Signature=iajFmX0ortvWFF7i0c-Xvbrum6lfLFsylC-g4hlGB52ISDUj1xkq2h-faKUB9haaAAdkSoEDPVZFk0GtjlFkYB5Dc6~T~3JNq6gSF2p20cwnSOhCXtZKRGltdidM4vpfnKcluupl3xL97EH5HmOGPwq3KSDb7XDYx-xfWCSd1IU_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

### Подсказки

Для этой задачи есть набор подсказок, которые должны помочь вам с решением.
Если вам не удаётся решить задачу и вы чувствуете, что у вас кончились идеи,
вы можете ими воспользоваться. Но сначала обязательно попробуйте решить задачу
без подсказок.

> [Подсказка 1.pdf](https://d3c33hcgiwev3.cloudfront.net/jUdmmfYwEeiAgQrXx6bp4g_8d8aff40f63011e88865336dfe4492c5__________-1.pdf?Expires=1643587200&Signature=FS~~GlMq~vqlGe2DFGnJB~4gGb6QJsWQmWoT8iWZ5dhxw7YPpKVuBMH3SBnWawciQsXuvDf94KHJnSL6HwIGhi~DykelgAYGWdJ5y52sNFQMinnzVT3hW-l2rB1thZEXyvjZzhOgCC2NMWMIaa~7zpcc5puO0xv136vJTKIq0hM_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)


> [Подсказка 2.pdf](https://d3c33hcgiwev3.cloudfront.net/mi__svYwEeiTKQ5ajE7PqA_9a70d8b0f63011e8a5c7eba363433e77__________-2.pdf?Expires=1643587200&Signature=bZ5nimTFEsyZs0JqEBtuEcdYaNa53cvkuBcUCNDlfA4YVKIi9f41ilYKdlcYBRDS3ntVu0QZU5bn~O9goODXA6UnF7sX9oeZZm4DOUjqygjxf-mdLhx6W~wd21llMJ8Io7kQ3zXrR~vwcNFXRReiMavuLcGin63c~uAmWK156TI_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)


> [Подсказка 3.pdf](https://d3c33hcgiwev3.cloudfront.net/AnrQ7PlgEei5Kg7DUflKxA_02e24500f96011e89a334bd1eaf43efc__________-3.pdf?Expires=1643587200&Signature=gK9vNo1ZsrxC92DV9Wyg18vfUeB4~aCSEK~D6VutSQwjCUWjvZ1XnSBdVGadIpTCsVouLyp-WlDlM9m8VZshPLANu394GA3ywatAmDLn008Fmhv0tKsOABFr6qfpA5GUcDkTlrLKAM31~TFdcIf-EtHvYmIwc62K406QxRZeyuM_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
