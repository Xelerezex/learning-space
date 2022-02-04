#include "test_runner.h"

/*
#include <forward_list>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;
*/

template <typename Type, typename Hasher>
class HashSet
{
    public:
        using BucketList = std::forward_list<Type>;

    public:
        explicit HashSet(
                size_t num_buckets,
                const Hasher& hasher = {}
        ) : Data(num_buckets, BucketList{}), func_hash(hasher), size(num_buckets)
        {
        }

        void Add(const Type& value)
        {
            if (!Has(value))
            {
                Data[func_hash(value) % size].push_front(value);
            }
        }

        bool Has(const Type& value) const
        {
            const auto &bucket = Data[func_hash(value) % size];

            const auto iter = std::find_if(
                bucket.begin(),
                bucket.end(),
                [&] (const Type item) {
                    return item == value;
                }
            );

            return (iter == bucket.end()) ? false : true;
        }

        void Erase(const Type& value)
        {
            Data[func_hash(value) % size].remove_if(
                [&] (const Type item) {
                    return item == value;
                }
            );
        }

        const BucketList& GetBucket(const Type& value) const
        {
            return Data[func_hash(value) % size];
        }

/*
        void Print() const
        {
            cerr << Data << endl;
        }
*/

    private:
        std::vector<BucketList> Data;
        Hasher func_hash;
        size_t size;
};

struct IntHasher
{
    size_t operator()(int value) const
    {
        // Это реальная хеш-функция из libc++, libstdc++.
        // Чтобы она работала хорошо, std::unordered_map
        // использует простые числа для числа бакетов
        return value;
    }
};

struct TestValue
{
    int value;

    bool operator==(TestValue other) const
    {
        return value / 2 == other.value / 2;
    }
};

struct TestValueHasher
{
    size_t operator()(TestValue value) const
    {
        return value.value / 2;
    }
};

void TestSmoke()
{
    HashSet<int, IntHasher> hash_set(2);
    hash_set.Add(3);
    hash_set.Add(4);

    ASSERT(hash_set.Has(3));
    ASSERT(hash_set.Has(4));
    ASSERT(!hash_set.Has(5));
    hash_set.Erase(3);

    ASSERT(!hash_set.Has(3));
    ASSERT(hash_set.Has(4));
    ASSERT(!hash_set.Has(5));

    hash_set.Add(3);
    hash_set.Add(5);

    ASSERT(hash_set.Has(3));
    ASSERT(hash_set.Has(4));
    ASSERT(hash_set.Has(5));
}

void TestEmpty()
{
    HashSet<int, IntHasher> hash_set(10);
    for (int value = 0; value < 10000; ++value)
    {
        ASSERT(!hash_set.Has(value));
    }
}

void TestIdempotency()
{
    HashSet<int, IntHasher> hash_set(10);
    hash_set.Add(5);
    ASSERT(hash_set.Has(5));
    hash_set.Add(5);
    ASSERT(hash_set.Has(5));
    hash_set.Erase(5);
    ASSERT(!hash_set.Has(5));
    hash_set.Erase(5);
    ASSERT(!hash_set.Has(5));
}

void TestEquivalence()
{
    HashSet<TestValue, TestValueHasher> hash_set(10);
    hash_set.Add(TestValue{2});
    hash_set.Add(TestValue{3});

    ASSERT(hash_set.Has(TestValue{2}));
    ASSERT(hash_set.Has(TestValue{3}));

    const auto& bucket = hash_set.GetBucket(TestValue{2});
    const auto& three_bucket = hash_set.GetBucket(TestValue{3});
    ASSERT_EQUAL(&bucket, &three_bucket);

    ASSERT_EQUAL(1, distance(begin(bucket), end(bucket)));
    ASSERT_EQUAL(2, bucket.front().value);
}


int main()
{
    TestRunner tr;
    RUN_TEST(tr, TestSmoke);
    RUN_TEST(tr, TestEmpty);
    RUN_TEST(tr, TestIdempotency);
    RUN_TEST(tr, TestEquivalence);

    return 0;
}
