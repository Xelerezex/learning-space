#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <deque>
#include <stdexcept>
#include <set>
using namespace std;


template <class T>
class ObjectPool
{
    public:
        T* Allocate()
        {
            if (released.empty())
            {
                T* pNewObj = new T;
                allocated.insert(pNewObj);
                return pNewObj;
            }
            else
            {
                auto [obj, flag] = allocated.insert(released.front());
                released.pop_front();
                return *obj;
            }
        }


        T* TryAllocate()
        {
            if (released.empty())
            {
                return nullptr;
            }
            else
            {
                auto [obj, flag] = allocated.insert(released.front());
                released.pop_front();
                return *obj;
            }
        }


        void Deallocate(T* object)
        {
            auto obj = allocated.find(object);

            if (obj == end(allocated))
            {
                throw invalid_argument("");
            }
            else
            {
                released.push_back(*obj);
                allocated.erase(obj);
            }

        }

        int GetSizeAllocated()
        {
            return allocated.size();
        }
        int GetSizeReleased()
        {
            return released.size();
        }

        ~ObjectPool()
        {
            while (!allocated.empty())
            {
                auto it = allocated.begin();
                delete *it;
                allocated.erase(it);
            }

            while (!released.empty())
            {
                auto it = released.front();
                delete it;
                released.pop_front();
            }

        }

    private:
        set<T*>   allocated;
        deque<T*> released;
};



void TestObjectPool()
{
    ObjectPool<string> pool;

    // --------------------------------------------------------------------------------------------//
    auto p1 = pool.Allocate();
    auto p2 = pool.Allocate();
    auto p3 = pool.Allocate();                  // alloc: 3, real: 0
    ASSERT_EQUAL(pool.GetSizeAllocated(), 3);
    ASSERT_EQUAL(pool.GetSizeReleased(), 0);
    // --------------------------------------------------------------------------------------------//
    *p1 = "first";
    *p2 = "second";
    *p3 = "third";                              // alloc: 3, real: 0
    // --------------------------------------------------------------------------------------------//
    pool.Deallocate(p2);                        // alloc: 2, real: 1  {first, third}  {second}
    ASSERT_EQUAL(pool.GetSizeAllocated(), 2);
    ASSERT_EQUAL(pool.GetSizeReleased(), 1);
    // --------------------------------------------------------------------------------------------//
    ASSERT_EQUAL(*pool.Allocate(), "second");   // alloc: 3, real: 0  {first, third, second}  {}
    ASSERT_EQUAL(pool.GetSizeAllocated(), 3);
    ASSERT_EQUAL(pool.GetSizeReleased(), 0);
    // --------------------------------------------------------------------------------------------//
    pool.Deallocate(p3);                        // alloc: 2, real: 1  {first, second}  {third}
    ASSERT_EQUAL(pool.GetSizeAllocated(), 2);
    ASSERT_EQUAL(pool.GetSizeReleased(), 1);
    // --------------------------------------------------------------------------------------------//
    pool.Deallocate(p1);                        // alloc: 1, real: 2  {second}  {third, first}
    ASSERT_EQUAL(pool.GetSizeAllocated(), 1);
    ASSERT_EQUAL(pool.GetSizeReleased(), 2);
    // --------------------------------------------------------------------------------------------//
    ASSERT_EQUAL(*pool.Allocate(), "third");   // alloc: 2, real: 1  {second, *third}  {first}
    ASSERT_EQUAL(pool.GetSizeAllocated(), 2);
    ASSERT_EQUAL(pool.GetSizeReleased(), 1);
    // --------------------------------------------------------------------------------------------//
    ASSERT_EQUAL(*pool.Allocate(), "first");   // alloc: 3, real: 0  {second, third, *first}  {}
    ASSERT_EQUAL(pool.GetSizeAllocated(), 3);
    ASSERT_EQUAL(pool.GetSizeReleased(), 0);
    // --------------------------------------------------------------------------------------------//
    pool.Deallocate(p1);                       // alloc: 2, real: 1  {second, third}  {first}
    ASSERT_EQUAL(pool.GetSizeAllocated(), 2);
    ASSERT_EQUAL(pool.GetSizeReleased(), 1);
    // --------------------------------------------------------------------------------------------//
    string* p4 = new string("fourth");
    try
    {
        pool.Deallocate(p4);
        ASSERT_EQUAL(0, 1);
    } catch (exception& ex){
        ASSERT_EQUAL(1, 1);
    }
}

int main()
{
    TestRunner tr;
    RUN_TEST(tr, TestObjectPool);
    return 0;
}
