## Restructing

В предыдущем видео мы показали, как пространства имён могут использоваться для структурирования кода
и его разбиения на логические блоки. В этой задаче вам предстоит попрактиковаться в этом.

Вам дана программа, которая умеет вычислять различные агрегации набора целых чисел: минимум, максимум,
сумму, среднее и моду. Каждая агрегация в программе реализована в виде отдельного класса, который
является потомком абстрактного базового класса ```StatsAggregator```. Эти классы имеют имена:

-   ```SumStatsAggregator```

-   ```MinStatsAggregator```

-   ```MaxStatsAggregator```

-   ```AverageStatsAggregator```

-   ```ModeStatsAggregator```

Как видите, у всех этих классов общий суффикс. Его частое использование может загромождать код и
затруднять его читаемость (особенно это касается файла с реализацией классов и файла с тестами).
Выполните следующие преобразования кода:

-   удалите из имён потомков``` StatsAggregator``` общий суффикс (например, ```SumStatsAggregator```
    надо переименовать в ```Sum```)

-   удалите из имён тестов общий суффикс (например, ```TestSumStatsAggregator``` надо переименовать в
    ```TestSum``` (см. юнит-тесты в файлах **stats_aggregator.h** и **stats_aggregator_test.cpp** ниже))

-   поместите классы-потомки ```StatsAggregator```, а также тесты для них в пространство имён
    ```StatsAggregators```

-   обновите файл **main.cpp** так, чтобы он корректно работал с новой структурой кода (в т.ч.
    вызывал юнит-тесты)

-   базовый класс ```StatsAggregator``` оставьте в глобальном пространстве имён

Как говорилось в видео, перемещение базового класса в пространство имён является делом вкуса. В этой
задаче мы просим оставить его в глобальном пространстве имён, потому что это позволяет не трогать код,
который работает с абстрактным интерфейсом, а не с его реализациями. Ради эксперимента, после сдачи
задачи, вы можете поместить ```StatsAggregator``` в пространство имён ```StatsAggregators``` и
посмотреть, какой ещё код придётся поменять и станет ли он от этого изменения проще.

>   [main](https://d3c33hcgiwev3.cloudfront.net/WcIyxvPWEeiTKQ5ajE7PqA_5a33df60f3d611e89fd09b4d4e7dcad1_main.cpp?Expires=1645920000&Signature=YM21SsmmKp1DdI5Z6dHGKqe9fvGXoSCNihVNYdveHFL4CeFnB8oWCIA~lbvJT4bVC~XjPtKV3I4K3mxa0JhPbR2KpdJPrY~Q3AscQnkVWHfxRh1j0sLtjH7ixewDDBToGa8lyE1bnSmzGXSTjhJVnad0-u982bqoP-2Hwoy94BI_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [stats_aggregator](https://d3c33hcgiwev3.cloudfront.net/ZpCMUvPWEeiixgqCUDoEfA_66a7e430f3d611e8a2daef8f5dce1878_stats_aggregator.cpp?Expires=1645920000&Signature=fQSqyGZg31V69UZKfBafC9~hmqYrf2rcdhirOf9TxGjBnf1ePrUMwo66Y7tqdw0GjUs6nBZYB2ENgn0b82X5I0ZacuYcdz9pKJQ2g~U5HlsJ~-z4yU2oLWgPLnIyteaifS3Yrl2T9LpZYATlEtBoEBKBsI29fW8zRW0NQwNTLCQ_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [stats_aggregator](https://d3c33hcgiwev3.cloudfront.net/cjoUwPPWEeiaxBKyA9PBAg_7250f7e0f3d611e8ae37cb8f9adb44bd_stats_aggregator.h?Expires=1645920000&Signature=S43Iqyo2vvsriRnxyU3hyDUMhYiIiqoBLGQH-03OzAKXfhsDtacUZrE5F2oJf8oIxcYnyBcRcoXhiHkV7oqEFxk6Zzduw1M02Hfcc59iFQxdCT3RGfz5NxUU9XNu8C88IX1LPrrxvE1BwSZYY1SMh~LWsq11pfa3pYBhNL5xLbM_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [stats_aggregator_test](https://d3c33hcgiwev3.cloudfront.net/fZuYcPPWEei5Kg7DUflKxA_7db2c960f3d611e8a2daef8f5dce1878_stats_aggregator_test.cpp?Expires=1645920000&Signature=OZACqPAb5gMqvtS73T8QgXSz4EpP98k2aPKEy1xm3mM9GiCEh1sD2-7A5hzZCDBi5WA2JP1pQJgUViB8yANfwM4DwtZi8caWNM7nbgXaxKCDBjDkhe-Xo17Sdv246Zi4eDwCbk~kZzq0exicj0rfl610BPq8dx02e1BRrIdOh5Y_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)


### Как будет тестироваться ваш код

Пришлите на проверку архив с переработанными файлами исходной программы. Тестирование будет проходить в несколько этапов.

1.  Сначала мы проверим, что в файле **stats_aggregator.h** есть классы ```StatsAggregator```,
    ```StatsAggregators::Sum```, ```StatsAggregators::Min```, ```StatsAggregators::Max```,
    ```StatsAggregators::Average```, ```StatsAggregators::Mode``` и ```StatsAggregators::Composite```,
    а также соответствующие функции с юнит-тестами.

2.  Затем запустим наши внутренние юнит-тесты для классов-потомков ```StatsAggregator```, чтобы
    убедиться, что они действительно реализуют его интерфейс.

3.  Далее мы запустим ваши юнит-тесты из файла **stats_aggregator_test.cpp** и убедимся, что они
    срабатывают на неверных реализациях классов и принимают верные.

4.  Наконец, мы соберём весь ваш проект и подадим ему в **stdin** несколько тестов, чтобы убедиться,
    что программа целиком работает корректно.
