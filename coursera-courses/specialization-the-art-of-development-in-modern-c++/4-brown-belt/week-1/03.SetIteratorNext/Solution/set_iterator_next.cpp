
#include "test_runner.h"
/*
#include <cassert>
#include <deque>
#include <iostream>

using namespace std;
*/

struct Node
{
    Node(int v, Node* p)
        : value(v)
        , parent(p)
    {}

    int value;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent;
};


class NodeBuilder
{
public:
    Node* CreateRoot(int value)
    {
        nodes.emplace_back(value, nullptr);
        return &nodes.back();
    }

    Node* CreateLeftSon(Node* me, int value)
    {
        assert( me->left == nullptr );
        nodes.emplace_back(value, me);
        me->left = &nodes.back();
        return me->left;
    }

    Node* CreateRightSon(Node* me, int value)
    {
        assert( me->right == nullptr );
        nodes.emplace_back(value, me);
        me->right = &nodes.back();
        return me->right;
    }

private:
    std::deque<Node> nodes;
};


Node* Next(Node* me)
{
    if (me->parent == nullptr && me->right == nullptr && me->left == nullptr)
    {
        return me->parent;
    }

    // У текущей вершины есть правое поддерево
    if (me->right != nullptr)
    {
        Node* output = me->right;
        while (output->left)
        {
            output = output->left;
        }
        return output;
    }
    // У текущей вершины нет правого поддерева, а она сама является левым ребёнком у её родителя
    else if (me->right == nullptr & me->parent->left == me)
    {
        return me->parent;
    }
    // У текущей вершины нет правого поддерева, а она сама является правым ребёнком у её родителя
    // Поднимайтесь из текущей вершины по родителям вверх, пока не окажетесь на левом ребёнке.
    // Следующей вершиной будет родитель текущей вершины

    else if (me->right == nullptr & me->parent->right == me)
    {
        Node* output = me->parent;

        while (output != output->parent->left && output->parent != nullptr)
        {
            output = output->parent;
        }

        if (output == nullptr)
        {
            return nullptr;
        }
        else
        {
            return output->parent;
        }
    }
    else
    {
        return nullptr;
    }
}


void Test1()
{
    NodeBuilder nb;

    Node* root = nb.CreateRoot(50);
    ASSERT_EQUAL( root->value, 50 );

    Node* l = nb.CreateLeftSon(root, 2);
    Node* min = nb.CreateLeftSon(l, 1);
    Node* r = nb.CreateRightSon(l, 4);
    ASSERT_EQUAL( min->value, 1);
    ASSERT_EQUAL( r->parent->value, 2 );

    nb.CreateLeftSon(r, 3);
    nb.CreateRightSon(r, 5);

    r = nb.CreateRightSon(root, 100);
    l = nb.CreateLeftSon(r, 90);
    nb.CreateRightSon(r, 101);

    Node* z = nb.CreateLeftSon(l, 89);
    r = nb.CreateRightSon(l, 91);

    ASSERT_EQUAL( Next(root)->value, 89 );
    ASSERT_EQUAL( Next(z)->value,  90 );
    ASSERT_EQUAL( Next(l)->value,  91 );
    ASSERT_EQUAL( Next(min)->value, 2 );
    ASSERT_EQUAL( Next(r)->value, 100 );

    while (min)
    {
        if (min == nullptr) { std::cout << "WORKING!" << std::endl; }
        std::cout << min->value << '\n';
        min = Next(min);
    }
}


void TestRootOnly()
{
    NodeBuilder nb;
    Node* root = nb.CreateRoot(42);
    ASSERT(Next(root) == nullptr);
};


int main()
{
    TestRunner tr;
    RUN_TEST(tr, Test1);
    RUN_TEST(tr, TestRootOnly);
    return 0;
}
