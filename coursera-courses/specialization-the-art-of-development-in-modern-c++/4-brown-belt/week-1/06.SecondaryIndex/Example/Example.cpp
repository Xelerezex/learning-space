#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

using namespace std;

struct Record
{
    string id;
    string title;
    string user;
    int timestamp;
    int karma;
};

class Database
{
    public:
        bool Put(const Record& record)
        {
            auto [it, inserted] = storage.insert(
                {record.id, Data {record, {}, {}, {}}}
            );

            if (!inserted) {
                return false;
            }

            auto& data = it->second;
            const Record* ptr = &data.record;
            data.timestamp_iter = timestamp_index.insert({record.timestamp, ptr});
            data.karma_iter = karma_index.insert({record.karma, ptr});
            data.user_iter = user_index.insert({record.user, ptr});
            return true;
        }

        const Record* GetById(const string& id) const
        {
            auto it = storage.find(id);
            if (it == storage.end())
            {
                return nullptr;
            }

            return &it->second.record;
        }

        bool Erase(const string& id)
        {
            auto it = storage.find(id);
            if (it == storage.end())
            {
                return false;
            }

            const auto& data = it->second;
            timestamp_index.erase(data.timestamp_iter);
            karma_index.erase(data.karma_iter);
            user_index.erase(data.user_iter);
            storage.erase(it);
            return true;
        }

        template <typename Callback>
        void RangeByTimestamp(int low, int high, Callback callback) const
        {
            auto it_begin = timestamp_index.lower_bound(low);
            auto it_end = timestamp_index.upper_bound(high);
            for (auto it = it_begin; it != it_end; ++it)
            {
                if (!callback(*it->second))
                {
                    break;
                }
            }
        }

        template <typename Callback>
        void RangeByKarma(int low, int high, Callback callback) const
        {
            auto it_begin = karma_index.lower_bound(low);
            auto it_end = karma_index.upper_bound(high);
            for (auto it = it_begin; it != it_end; ++it)
            {
                if (!callback(*it->second))
                {
                    break;
                }
            }
        }

        template <typename Callback>
        void AllByUser(const string& user, Callback callback) const
        {
            auto [it_begin, it_end] = user_index.equal_range(user);
            for (auto it = it_begin; it != it_end; ++it)
            {
                if (!callback(*it->second))
                {
                    break;
                }
            }
        }

    private:
        template <typename Type>
        using Index = multimap<Type, const Record*>;

        struct Data {
            Record record;
            Index<int>::iterator timestamp_iter;
            Index<int>::iterator karma_iter;
            Index<string>::iterator user_iter;
        };

    private:
        unordered_map<string, Data> storage;
        Index<int> timestamp_index;
        Index<int> karma_index;
        Index<string> user_index;
};
