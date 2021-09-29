#include "test_runner.h"
/*
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
using namespace std;
*/

template <class T>
class ObjectPool {
    public:
        T* Allocate() {
            if (released.empty()) {
                T* pNewObj = new T;
                allocated.push(pNewObj);
                return pNewObj;
            } else {
                T* pNewObj = new T(*released.front());
                released.pop();
                allocated.push(pNewObj);
                return pNewObj;
            }
        }

        T* TryAllocate() {
            if (released.empty()) {
                T* pNewObj = new T;
                allocated.push(pNewObj);
                return pNewObj;
            } else {
                return nullptr;
            }
        }

        void Deallocate(T* object);

        ~ObjectPool();

    private:
        queue<T*> allocated;
        queue<T*> released;
};



void TestObjectPool() {
    ObjectPool<string> pool;

    auto p1 = pool.Allocate();
    auto p2 = pool.Allocate();
    auto p3 = pool.Allocate();

    *p1 = "first";
    *p2 = "second";
    *p3 = "third";

    pool.Deallocate(p2);
    ASSERT_EQUAL(*pool.Allocate(), "second");

    pool.Deallocate(p3);
    pool.Deallocate(p1);
    ASSERT_EQUAL(*pool.Allocate(), "third");
    ASSERT_EQUAL(*pool.Allocate(), "first");

    pool.Deallocate(p1);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestObjectPool);
    return 0;
}
