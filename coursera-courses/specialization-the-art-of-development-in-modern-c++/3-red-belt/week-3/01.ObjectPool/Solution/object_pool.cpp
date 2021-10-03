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
                T* pOldObj = released.front();
                allocated.push(pOldObj);
                released.pop();

                return pOldObj;
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


        void Deallocate(T* object) {
            queue<T*> temporary;
            temporary.swap(released);

            while(!temporary.empty()) {
                if (temporary.front() == object) {
                    released.push(temporary.front());

                    delete temporary.front();
                    temporary.pop();
                }
            }


/*            if (temporary.size() >= 1) {
                delete temporary.front();
                temporary.pop();

                throw invalid_argument("");
            }*/

            released.swap(temporary);
        }

        size_t GetSizeAllocated() { return allocated.size(); }
        size_t GetSizeReleased()  { return released.size(); }

        ~ObjectPool() {
            while(!allocated.empty()) {
                delete allocated.front();
                allocated.pop();
            }

            while(!released.empty()) {
                delete released.front();
                released.pop();
            }
        }

    private:
        queue<T*> allocated;
        queue<T*> released;
};



void TestObjectPool() {
    ObjectPool<string> pool;

    auto p1 = pool.Allocate();
    auto p2 = pool.Allocate();
    auto p3 = pool.Allocate();

    ASSERT_EQUAL(pool.GetSizeAllocated(), 3);

    *p1 = "first";
    *p2 = "second";
    *p3 = "third";

    pool.Deallocate(p2);
    ASSERT_EQUAL(pool.GetSizeAllocated(), 2);
    ASSERT_EQUAL(pool.GetSizeReleased(), 1);


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
