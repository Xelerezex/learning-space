Односвязный список — классический пример структуры данных, для реализации которой нужно пользоваться памятью в куче.
В этой задаче вам нужно реализовать шаблон класса LinkedList, который представляет собой односвязный список и
обладает следующим интерфейсом:

```cpp
template <typename T>
class LinkedList {
public:
    struct Node {
        T value;
        Node* next = nullptr;
    };

    ~LinkedList();

    void PushFront(const T& value);
    void InsertAfter(Node* node, const T& value);
    void RemoveAfter(Node* node);
    void PopFront();

    Node* GetHead() { return head; }
    const Node* GetHead() const { return head; }

private:
    Node* head = nullptr;
};
```

-   Метод GetHead возвращает указатель на голову списка, он используется для перебора элементов списка
    (см. шаблон ToVector в заготовке решения)

-   Метод PushFront добавляет новый элемент в голову списка.

-   Метод InsertAfter вставляет новый элемент в список так, чтобы он шёл после узла node. Если node == nullptr,
    метод эквивалентен PushFront

-   Метод PopFront удаляет элемент из головы списка и освобождает выделенную под него память. Если список пуст,
    метод завершается корректно. Если после выполнения метода список стал пустым, метод GetHead должен возвращать nullptr

-   Метод RemoveAfter должен удалять из списка элемент, который следует за узлом node, и освобождать выделенную
    под него память. Если node == nullptr, метод эквивалентен PopFront. Если node->next == nullptr, то метод должен корректно завершаться.

-   Все методы, перечисленные выше, должны работать за O(1)

-   Деструктор класса LinkedList освобождает всю память, выделенную для хранения элементов списка.

#### Файл с заготовкой решения

> [linked_list.cpp](https://d3c33hcgiwev3.cloudfront.net/Pl08iWTGEeiEwg4WmF3VaA_3e87598064c611e8bf8f1bc409774e1f_linked_list.cpp?Expires=1633651200&Signature=iZDc1m938doro3B6-Ziu5lv4e7iYz9iU48qfMyt8EpnAIcYLs3jULMci5hFp5ZuWelBomojgIRtppj7cJDdDFHFa7GRPm8mCCWNQLKiKcg6g13-87G5xozxR4L0BOKV7dFwNigimirqLul91D8ONjAtUWDVMc2Be63ScVWuJ0IE_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
