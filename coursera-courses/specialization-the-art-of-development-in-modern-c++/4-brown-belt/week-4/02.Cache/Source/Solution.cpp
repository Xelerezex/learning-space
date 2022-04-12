#include "Common.h"

using namespace std;

class LruCache : public ICache
{
    public:
        LruCache (
            shared_ptr<IBooksUnpacker> books_unpacker,
            const Settings& settings
        )
        {
          // реализуйте метод
        }

        BookPtr GetBook(const string& book_name) override
        {
          // реализуйте метод
        }
};


unique_ptr<ICache> MakeCache (
    shared_ptr<IBooksUnpacker> books_unpacker,
    const ICache::Settings& settings
)
{
  // реализуйте функцию
}
