#include "test_runner.h"

#include <vector>
using namespace std;


template <typename T>
class LinkedList {
public:
    struct Node {
        T value;
        Node* next = nullptr;
    };

    void PushFront(const T& value) {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->next  = head;
        head = newNode;
    }


    void InsertAfter(Node* node, const T& value) {
        if (node == nullptr) {
            PushFront(value);
        } else if (node->next == nullptr) {
            Node* newNode = new Node;
            newNode->value = value;
            newNode->next  = nullptr;
            node->next = newNode;
        } else {
            Node* newNode = new Node;
            newNode->value = value;
            newNode->next  = node->next;
            node->next = newNode;
        }
    }


    void PopFront() {
        if (head != nullptr) {
            auto forDel = head;
            head = head->next;
            delete forDel;
            forDel = nullptr;
        }
    }


    void RemoveAfter(Node* node) {
        if (node == nullptr) {
            PopFront();
        } else if (node->next == nullptr) {
            return;
        } else {
            auto deleted = node->next;
            node->next = (node->next)->next;
            delete deleted;
            deleted = nullptr;
        }
    }


    Node* GetHead() { return head; }
    const Node* GetHead() const { return head; }

    ~LinkedList() {
        // auto == LinkedList<int>::Node *
        for (auto node = head; node;) {

            node = node->next;
            delete head;
            head = node;

            if (head == nullptr) {
                delete node;
                node = nullptr;
            }
        }
        delete head;
        head = nullptr;
    }

private:
    Node* head = nullptr;
};

template <class L>
ostream& operator << (ostream& os, LinkedList <L>& l);

template <typename T>
vector<T> ToVector(const LinkedList<T>& list) {
    vector<T> result;
    for (auto node = list.GetHead(); node; node = node->next) {
        result.push_back(node->value);
    }
    return result;
}


void TestPushFront() {
    LinkedList<int> list;

    list.PushFront(1);
    ASSERT_EQUAL(list.GetHead()->value, 1);

    list.PushFront(2);
    ASSERT_EQUAL(list.GetHead()->value, 2);

    list.PushFront(3);
    ASSERT_EQUAL(list.GetHead()->value, 3);

    list.PushFront(4);
    ASSERT_EQUAL(list.GetHead()->value, 4);

    const vector<int> expected = {4, 3, 2, 1};
    ASSERT_EQUAL(ToVector(list), expected);

    cerr << list << endl;
}


void TestInsertAfter() {
    LinkedList<string> list;

    list.InsertAfter(nullptr, "a");
    auto head = list.GetHead();
    ASSERT(head);
    ASSERT_EQUAL(head->value, "a");

    list.InsertAfter(head, "b");
    const vector<string> expected1 = {"a", "b"};
    ASSERT_EQUAL(ToVector(list), expected1);

    list.InsertAfter(head, "c");
    const vector<string> expected2 = {"a", "c", "b"};
    ASSERT_EQUAL(ToVector(list), expected2);

    auto last = (list.GetHead()->next)->next;
    list.InsertAfter(last, "Z");
    const vector<string> expected3 = {"a", "c", "b", "Z"};
    ASSERT_EQUAL(ToVector(list), expected3);
}


void TestRemoveAfter() {
    LinkedList<int> list;
    for (int i = 1; i <= 5; ++i) {
        list.PushFront(i);
    }

    const vector<int> expected = {5, 4, 3, 2, 1};
    ASSERT_EQUAL(ToVector(list), expected);

    auto next_to_head = list.GetHead()->next;
    list.RemoveAfter(next_to_head); // удаляем 3
    list.RemoveAfter(next_to_head); // удаляем 2

    const vector<int> expected1 = {5, 4, 1};
    ASSERT_EQUAL(ToVector(list), expected1);

    while (list.GetHead()->next) {
        list.RemoveAfter(list.GetHead());
    }
    ASSERT_EQUAL(list.GetHead()->value, 5);
}


void TestPopFront() {
    LinkedList<int> list;

    list.PopFront();

    for (int i = 1; i <= 5; ++i) {
        list.PushFront(i);
    }
    for (int i = 1; i <= 5; ++i) {
        list.PopFront();
    }
    ASSERT(list.GetHead() == nullptr);
}


int main() {
    TestRunner tr;
    RUN_TEST(tr, TestPushFront);
    RUN_TEST(tr, TestInsertAfter);
    RUN_TEST(tr, TestRemoveAfter);
    RUN_TEST(tr, TestPopFront);

    return 0;
}


//-------------FOR-LINKED-LIST
template <class L>
ostream& operator << (ostream& os, LinkedList <L>& l) {
    for (auto node = l.GetHead(); node; node = node->next) {
        os << node->next << " : " << node->value << "; ";
    }
    return os;
}
