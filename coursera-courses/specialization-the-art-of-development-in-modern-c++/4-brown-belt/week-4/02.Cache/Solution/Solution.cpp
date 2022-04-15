#include "Common.h"

#include <unordered_map>
#include <list>
#include <mutex>

using namespace std;

class LruCache : public ICache {
    public:
        LruCache(
                shared_ptr<IBooksUnpacker> books_unpacker_,
                const Settings &settings_
        )
            : books_unpacker(move(books_unpacker_))
            , settings(settings_)
            , total_size(0)
        {
        }

        BookPtr GetBook(const string &book_name) override
        {
            lock_guard<mutex> lock(mx);

            if (auto it = cache.find(book_name); it != cache.end())
            {
                rate.splice(rate.begin(), rate, it->second);
                return rate.front();
            }

            auto book = books_unpacker->UnpackBook(book_name);

            if (book->GetContent().size() > settings.max_memory)
            {
                rate.clear();
                cache.clear();
                total_size = 0;

                return move(book);
            }

            total_size += book->GetContent().size();

            if (total_size > settings.max_memory)
            {
                while (total_size > settings.max_memory)
                {
                    total_size -= rate.back()->GetContent().size();
                    cache.erase(rate.back()->GetName());
                    rate.pop_back();
                }
            }

            rate.emplace_front(move(book));
            cache[rate.front()->GetName()] = rate.begin();

            return *cache[book_name];
        }

        ~LruCache() override
        {
        }

    private:
        shared_ptr<IBooksUnpacker> books_unpacker;
        const Settings settings;
        list<BookPtr> rate;
        unordered_map<string, list<BookPtr>::iterator> cache;
        size_t total_size;
        mutable mutex mx;
};


unique_ptr<ICache> MakeCache(
        shared_ptr<IBooksUnpacker> books_unpacker,
        const ICache::Settings &settings
)
{
    return make_unique<LruCache>(books_unpacker, settings);
}
