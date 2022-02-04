## Set Iterator Next

На лекциях вам было рассказано о внутреннем устройстве контейнеров map и set. Обычно map и set
реализованы как двоичные деревья поиска.

Также вы узнали о том, как производится обход дерева с помощью итераторов.

В данной задаче мы будем работать не с контейнером set, но с аналогичным двоичным деревом поиска,
состоящим из следующих вершин:

```cpp
struct Node {
    int value;
    Node* left;
    Node* right;
    Node* parent;
};
```

Где:

-   ```value``` - значение, хранящееся в вершине;

-   ```left``` и ```right``` - указатели на дочерние вершины (оба равны ```nullptr``` для листьев
    дерева);

-   ```parent``` - указатель на родительскую вершину (равен ```nullptr``` для корня дерева).

Допустим, что для обхода дерева мы используем не специальный итератор, а просто
указатель на вершину ```Node*```.

Вам требуется реализовать функцию

```cpp
Node* Next(Node* node);
```

, возвращающую указатель на следующую по возрастанию значения вершину.

Функция должна вернуть ```nullptr``` в случае, если текущая вершина -- последняя в дереве.

### Заготовка решения задачи

>   [set_iterator_next.cpp](https://d3c33hcgiwev3.cloudfront.net/IZpqe_exEeiixgqCUDoEfA_21fb9cd0f7b111e88828fb98e26a0fcb_set_iterator_next.cpp?Expires=1644105600&Signature=dpwABkPm2EimG1z9SpWhJmCzhXRkSZ00B8VKt2Fb3SKbuxxjdksOmCjxoV3~2CSWr36dgzNCW9RUnbMysFUc9VqRdhNHgD-X1RmP3ZL9cDwb4Us5Lgs5PanaPsFKDHo8qDRXdlQ1A8wZu80Y0GkQFjfsn2pAuMN-errzoMuFAsw_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

### Подсказки

Для этой задачи есть набор подсказок, которые должны помочь вам с решением. Если вам не удаётся
решить задачу и вы чувствуете, что у вас кончились идеи, вы можете ими воспользоваться. Но
сначала обязательно попробуйте решить задачу без подсказок.

>   [Подсказка 1.pdf](https://d3c33hcgiwev3.cloudfront.net/dnRfw_IlEeiTKQ5ajE7PqA_76c4c980f22511e8a63c6544b1563662__________-1.pdf?Expires=1644105600&Signature=BMlvwIHkPqHcm4PlF7LINE1tyFaat8E0W79GMjC-46YoZQb5ZuoL8xFJVml4vu4CLpKwzbmbpCIJzcTUifHFXQdgDIG2dTOKxg27VcVsXXYpzzDyz9psqCr~fw5fo5PNmf-n7487afWdSgUsHDp0To48YcbiC8PKTSWe3PnO3hE_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [Подсказка 2.pdf](https://d3c33hcgiwev3.cloudfront.net/g9pl0PIlEeilxxL_ZeRz_A_8406ccb0f22511e8a63c6544b1563662__________-2.pdf?Expires=1644105600&Signature=NO1cPd2UHOF3ZMhF4loyEHoLQWGDj9ANOOTlmoMFYC4dgZsU~tOPHjWaD~i5KMSIxKsBsWFEMfoyfMyFRg6R1AlmC1G24dJyPW7EMNcQtEsibPhCONtmMm7o5oewstM7i-tmjqZug6FEaAISEHQdewnmH0HUTnTvhjVfkSEGRNY_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [Подсказка 3.pdf](https://d3c33hcgiwev3.cloudfront.net/jffQIfIlEeiAgQrXx6bp4g_8e20dbf0f22511e8a63c6544b1563662__________-3.pdf?Expires=1644105600&Signature=fh2k-E~ug773xuLg~BkeJUgC5f8Gc5o7fJPGfiQob1f1yh2WhZwjV-uIo-e35D7YjXyvwOyiFPYMe4kNH6TZdKjK8gXMXwiFNTHY3wIG-v6Qd8gh~~hny6k2IzPnlCTLflck2LLFnXI0MbGL8WlPknQnoqJMS44ANragzMG86gw_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [Подсказка 4.pdf](https://d3c33hcgiwev3.cloudfront.net/l85uVfIlEeiaxBKyA9PBAg_97f97560f22511e8867d83b1b5022ae3__________-4.pdf?Expires=1644105600&Signature=XGu8Ko2ZrPnzGrwfBb9yuGGCbs2pS-2QOBCqbWfrmrwu0THKmKf-3gMGHEVrtHEOXqeIcHwicGFogjob0Z2gaaAqwEiBctSzQi~HOj2Wid49NFkRLnOw2Sv9~aH-deuzcmB~Mb-63PLk5akLhRoi9XBNkBbOF2Y-BhlNvY-QE~0_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
