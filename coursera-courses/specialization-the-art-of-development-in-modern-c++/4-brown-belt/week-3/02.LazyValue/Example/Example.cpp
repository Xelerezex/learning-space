#include <functional>
#include <optional>
using namespace std;

template <typename T>
class LazyValue
{
public:
    explicit LazyValue(std::function<T()> init) : init_(std::move(init))
    {
    }

    bool HasValue() const
    {
        return value_.has_value();
    }

    const T& Get() const
    {
        if (!value_)
        {
            value_ = init_();
        }
        return *value_;
    }

private:
    std::function<T()> init_;
    mutable std::optional<T> value_;
};
