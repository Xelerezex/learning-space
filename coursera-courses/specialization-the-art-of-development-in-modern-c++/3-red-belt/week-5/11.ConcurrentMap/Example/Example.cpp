#include <future>
#include <mutex>
#include <map>
#include <vector>
#include <utility>
using namespace std;

template <typename T>
T Abs(T x) {
    return x < 0 ? -x : x;
}

auto Lock(mutex& m) {
    return lock_guard<mutex>{m};
}

template <typename K, typename V>
class ConcurrentMap {
public:
    static_assert(
        is_convertible_v<K, uint64_t>,
        "ConcurrentMap supports only integer keys"
    );

    struct Access {
        lock_guard<mutex> guard;
        V& ref_to_value;

        Access(const K& key, pair<mutex, map<K, V>>& bucket_content)
            : guard(bucket_content.first)
            , ref_to_value(bucket_content.second[key])
        {
        }
    };

    explicit ConcurrentMap(size_t bucket_count)
        : data(bucket_count)
    {
    }

    Access operator[](const K& key) {
        auto& bucket = data[Abs(key) % data.size()];
        return {key, bucket};
    }

    map<K, V> BuildOrdinaryMap() {
        map<K, V> result;
        for (auto& [mtx, mapping] : data) {
            auto g = Lock(mtx);
            result.insert(begin(mapping), end(mapping));
        }
        return result;
    }

private:
    vector<pair<mutex, map<K, V>>> data;
};
