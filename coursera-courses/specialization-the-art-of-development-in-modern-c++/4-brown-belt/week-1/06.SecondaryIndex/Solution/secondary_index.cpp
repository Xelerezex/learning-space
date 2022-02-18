#include "test_runner.h"

#include <unordered_map>
// #include <multimap>
#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Record
{
    string id;
    string title;
    string user;
    int timestamp;
    int karma;

    bool operator== (const Record &other) const
    {
        return (id == other.id)
            && (title == other.title)
            && (user == other.user)
            && (timestamp == other.timestamp)
            && (karma == other.karma);
    }

    bool operator< (const Record &other) const
    {
        return (id < other.id)
            && (title < other.title)
            && (user < other.user)
            && (timestamp < other.timestamp)
            && (karma < other.karma);
    }
};

ostream& operator << (ostream& os, const Record &record)
{
    os << "("
       << record.id        << ", "
       << record.title     << ", "
       << record.user      << ", "
       << record.timestamp << ", "
       << record.karma;
    return os << ")";
}

// Реализуйте этот класс
class Database
{
    private:
        //-----------------------------------------------------------------------------------------//
        using IdValue           = std::string;
        using UserValue         = std::string;
        using TimestampValue    = int;
        using KarmaValue        = int;
        using DataBaseIterator  = typename map<IdValue, Record>::iterator;
        using UserIterator      = typename multimap<UserValue, DataBaseIterator>::iterator;
        using TimestampIterator = typename multimap<TimestampValue, DataBaseIterator>::iterator;
        using KarmaIterator     = typename multimap<KarmaValue, DataBaseIterator>::iterator;
        //-----------------------------------------------------------------------------------------//
        struct RecordReference
        {
            DataBaseIterator  id_iterator;
            UserIterator      user_iterator;
            TimestampIterator timestamp_iterator;
            KarmaIterator     karma_iterator;

            bool operator== (const RecordReference &other) const
            {
                return (*id_iterator        == *other.id_iterator)
                    && (*user_iterator      == *other.user_iterator)
                    && (*timestamp_iterator == *other.timestamp_iterator)
                    && (*karma_iterator     == *other.karma_iterator);
            }

            bool operator< (const RecordReference &other) const
            {
                return (id_iterator->first        < other.id_iterator->first)
                    && (user_iterator->first      < other.user_iterator->first)
                    && (timestamp_iterator->first < other.timestamp_iterator->first)
                    && (karma_iterator->first     < other.karma_iterator->first);
            }
        };

/*        struct RecordHasher
        {
            size_t operator() (const string &str) const
            {
                const size_t coef = 2213;
                const hash<string> id_hasher;
                return coef * id_hasher(str);
            }
        };*/
        //-----------------------------------------------------------------------------------------//
        unordered_map<IdValue, RecordReference>  DataBaseLinks;
        map<IdValue, Record>                                   DataBase;
        multimap<UserValue, DataBaseIterator>                  UserBase;
        multimap<TimestampValue, DataBaseIterator>             TimestampBase;
        multimap<KarmaValue, DataBaseIterator>                 KarmaBase;
        //-----------------------------------------------------------------------------------------//
    public:
        // True, if insertion is successfull, else false
        bool Put(const Record& record)
        {
            if (const auto [iterator, flag] = DataBase.insert({record.id, record}); flag == true)
            {
                const auto user_iterator      = UserBase.insert({record.user, iterator});
                const auto timestamp_iterator = TimestampBase.insert({record.timestamp, iterator});
                const auto karma_iterator     = KarmaBase.insert({record.karma, iterator});

                DataBaseLinks.insert({
                    record.id,
                    RecordReference{
                        iterator,
                        user_iterator,
                        timestamp_iterator,
                        karma_iterator
                    }
                });

                return flag;
            }
            else
            {
                return false;
            }
        }

        // Find obj by id, return nullptr if there is no object
        const Record* GetById(const string& id) const
        {
            if (const auto iterator = DataBaseLinks.find(id); iterator != DataBaseLinks.end())
            {
                const auto recordreference_iterator = iterator->second;
                const auto database_iterator        = recordreference_iterator.id_iterator;
                return &(database_iterator->second);
            }
            else
            {
                return nullptr;
            }
        }

        // Find than delete obj, if there is no obj return false
        bool Erase(const string& id)
        {
            if (const auto iterator = DataBaseLinks.find(id); iterator != DataBaseLinks.end())
            {
                const auto recordreference_iterator = iterator->second;
                const auto database_iterator        = recordreference_iterator.id_iterator;
                const auto userbase_iterator        = recordreference_iterator.user_iterator;
                const auto timestampbase_iterator   = recordreference_iterator.timestamp_iterator;
                const auto karmabase_iterator       = recordreference_iterator.karma_iterator;
                KarmaBase.erase(karmabase_iterator);
                TimestampBase.erase(timestampbase_iterator);
                UserBase.erase(userbase_iterator);
                DataBase.erase(database_iterator);
                DataBaseLinks.erase(iterator);

                return true;
            }
            else
            {
                return false;
            }
        }


        template <typename Iterator, typename Callback>
        inline void LookUp(const Iterator low, const Iterator high, Callback callback) const
        {
            for (auto iteration = low; iteration != high;)
            {
                const auto record = (iteration->second)->second;
                if (callback(record) == false)
                {
                    break;
                }
                else
                {
                    ++iteration;
                }
            }
        }

        // Analog: Count in diapason
        // Goes from [low, high] of timestamp, call callback, if callback == false, stop iteration
        template <typename Callback>
        void RangeByTimestamp(int low, int high, Callback callback) const
        {
            const auto low_iterator = TimestampBase.lower_bound(low);
            const auto high_iterator = TimestampBase.upper_bound(high);
            LookUp(low_iterator, high_iterator, callback);
        }

        // Analog: Count in diapason
        // Goes from [low, high] of karma, call callback, if callback == false, stop iteration
        template <typename Callback>
        void RangeByKarma(int low, int high, Callback callback) const
        {
            const auto low_iterator = KarmaBase.lower_bound(low);
            const auto high_iterator = KarmaBase.upper_bound(high);
            LookUp(low_iterator, high_iterator, callback);
        }

        // Analog: Count in diapasone
        // Goes from [low, high] of user, call callback, if callback == false, stop iteration
        template <typename Callback>
        void AllByUser(const string& user, Callback callback) const
        {
            const auto low_iterator = UserBase.lower_bound(user);
            const auto high_iterator = UserBase.upper_bound(user);
            LookUp(low_iterator, high_iterator, callback);
        }



        void Print() const
        {
            std::cerr << std::endl;
            {
                std::cerr << "DataBaseLinks : " << std::endl << "\t {";
                bool first = true;
                for (const auto &pair : DataBaseLinks)
                {
                    if (!first)
                    {
                        std::cerr << ", ";
                    }
                    first = false;
                    std::cerr << pair.first;
                }
                std::cerr << "}" << std::endl;
            }
            {
                std::cerr << "DataBase : " << std::endl << "\t ";
                bool first = true;
                for (const auto &pair : DataBase)
                {
                    if (!first)
                    {
                        std::cerr << "," << std::endl << "\t ";
                    }
                    first = false;
                    std::cerr << "{" << pair.first << " : " << pair.second << "}";
                }
                std::cerr << std::endl;
            }
            {
                std::cerr << "UserBase : " << std::endl << "\t {";
                bool first = true;
                for (const auto &pair : UserBase)
                {
                    if (!first)
                    {
                        std::cerr << ", ";
                    }
                    first = false;
                    std::cerr << pair.first;
                }
                std::cerr << "}" << std::endl;
            }
            {
                std::cerr << "TimestampBase : " << std::endl << "\t {";
                bool first = true;
                for (const auto &pair : TimestampBase)
                {
                    if (!first)
                    {
                        std::cerr << ", ";
                    }
                    first = false;
                    std::cerr << pair.first;
                }
                std::cerr << "}" << std::endl;
            }
            {
                std::cerr << "KarmaBase : " << std::endl << "\t {";
                bool first = true;
                for (const auto &pair : KarmaBase)
                {
                    if (!first)
                    {
                        std::cerr << ", ";
                    }
                    first = false;
                    std::cerr << pair.first;
                }
                std::cerr << "}" << std::endl;
            }
            std::cerr << std::endl;
        }
};




void TestRangeBoundaries()
{
    const int good_karma = 1000;
    const int bad_karma = -10;

    Database db;
    ASSERT(db.Put({"id1", "Hello there", "master", 1536107260, good_karma}));
    ASSERT(db.Put({"id2", "O>>-<", "general2", 1536107260, bad_karma}));
    ASSERT(db.Put({"id7", "WIoFLY", "somebody", 1536107260, 500}));
    ASSERT(!db.Put({"id7", "WIoFLY", "somebody", 1536107260, 500}));
    // db.Print();

    ASSERT_EQUAL(*db.GetById("id7"), (Record{"id7", "WIoFLY", "somebody", 1536107260, 500}));
    ASSERT(db.Erase("id7"));
    ASSERT_EQUAL(db.GetById("id10"), nullptr);
    ASSERT(!db.Erase("id7"));
    // db.Print();

    int count = 0;
    db.RangeByKarma(
        bad_karma,
        good_karma,
        [&count] (const Record&) {
            ++count;
            return true;
    });

    ASSERT_EQUAL(2, count);

}

void TestSameUser()
{
    Database db;
    db.Put({"id1", "Don't sell", "master", 1536107260, 1000});
    db.Put({"id2", "Rethink life", "master", 1536107260, 2000});

    // db.Print();

    int count = 0;
    db.AllByUser(
        "master",
        [&count] (const Record&) {
            ++count;
            return true;
    });

    ASSERT_EQUAL(2, count);
}


void TestReplacement()
{
    const string final_body = "Feeling sad";

    Database db;
    db.Put({"id", "Have a hand", "not-master", 1536107260, 10});
    db.Erase("id");
    db.Put({"id", final_body, "not-master", 1536107260, -10});

    auto record = db.GetById("id");
    ASSERT(record != nullptr);
    ASSERT_EQUAL(final_body, record->title);
}

int main()
{
    TestRunner tr;
    RUN_TEST(tr, TestRangeBoundaries);
    RUN_TEST(tr, TestSameUser);
    RUN_TEST(tr, TestReplacement);
    return 0;
}
