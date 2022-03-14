#include "test_runner.h"

#include <functional>
#include <string>
#include <optional>

using namespace std;

template <typename T>
class LazyValue
{
    public:
        explicit LazyValue(std::function<T()> init)
            : init_func(init),
              has_value(false),
              object{}
        {}

        bool HasValue() const
        {
            return has_value;
        }

        const T& Get() const
        {
            if (!HasValue())
            {
                Create();
                return object.value();
            }
            else
            {
                return object.value();
            }
        }

    private:
        const std::function<T()> init_func;
        mutable bool has_value;
        mutable optional<T> object;

        void Create() const
        {
            object = init_func();
            has_value = true;
        }
};

void UseExample()
{
    const string big_string = "Giant amounts of memory";

    LazyValue<string> lazy_string([&big_string] { return big_string; });

    ASSERT(!lazy_string.HasValue());
    ASSERT_EQUAL(lazy_string.Get(), big_string);
    ASSERT_EQUAL(lazy_string.Get(), big_string);
}

void TestInitializerIsntCalled()
{
    bool called = false;

    {
        LazyValue<int> lazy_int(
          [&called] {
              called = true;
              return 0;
          }
        );
    }
    ASSERT(!called);
}

int main()
{
    TestRunner tr;
    RUN_TEST(tr, UseExample);
    RUN_TEST(tr, TestInitializerIsntCalled);
    return 0;
}
