#include "test_runner.h"

#include <unordered_map>
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
        using PointerRecord     = const Record *;
        using UserValue         = std::string;
        using TimestampValue    = int;
        using KarmaValue        = int;
        using UserIterator      = typename multimap<UserValue, PointerRecord>::iterator;
        using TimestampIterator = typename multimap<TimestampValue, PointerRecord>::iterator;
        using KarmaIterator     = typename multimap<KarmaValue, PointerRecord>::iterator;
        //-----------------------------------------------------------------------------------------//
        struct RecordWithReference
        {
            Record            record;
            UserIterator      user_iterator;
            TimestampIterator timestamp_iterator;
            KarmaIterator     karma_iterator;

            bool operator== (const RecordWithReference &other) const
            {
                return (record              == record)
                    && (*user_iterator      == *other.user_iterator)
                    && (*timestamp_iterator == *other.timestamp_iterator)
                    && (*karma_iterator     == *other.karma_iterator);
            }

            bool operator< (const RecordWithReference &other) const
            {
                return (record                    < record)
                    && (user_iterator->first      < other.user_iterator->first)
                    && (timestamp_iterator->first < other.timestamp_iterator->first)
                    && (karma_iterator->first     < other.karma_iterator->first);
            }
        };

        //-----------------------------------------------------------------------------------------//
        unordered_map<IdValue, RecordWithReference>         DataBase;
        multimap<UserValue, PointerRecord>                  UserBase;
        multimap<TimestampValue, PointerRecord>             TimestampBase;
        multimap<KarmaValue, PointerRecord>                 KarmaBase;
        //-----------------------------------------------------------------------------------------//
    public:
        // True, if insertion is successfull, else false
        bool Put(const Record& record)
        {
            if (
                const auto [iterator, flag] =
                DataBase.insert({record.id, {record, UserBase.end(), TimestampBase.end(), KarmaBase.end()}});
                flag == true
                )
            {
                const Record * record_pointer = &(iterator->second).record;

                const auto user_iterator      = UserBase.insert({record.user, record_pointer});
                const auto timestamp_iterator = TimestampBase.insert({record.timestamp, record_pointer});
                const auto karma_iterator     = KarmaBase.insert({record.karma, record_pointer});

                (iterator->second).user_iterator = user_iterator;
                (iterator->second).timestamp_iterator = timestamp_iterator;
                (iterator->second).karma_iterator = karma_iterator;

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
            if (const auto iterator = DataBase.find(id); iterator != DataBase.end())
            {
                const auto record_reference = &iterator->second.record;
                return record_reference;
            }
            else
            {
                return nullptr;
            }
        }

        // Find than delete obj, if there is no obj return false
        bool Erase(const string& id)
        {
            if (const auto iterator = DataBase.find(id); iterator != DataBase.end())
            {
                const auto database_iterator        = iterator;
                const auto userbase_iterator        = database_iterator->second.user_iterator;
                const auto timestampbase_iterator   = database_iterator->second.timestamp_iterator;
                const auto karmabase_iterator       = database_iterator->second.karma_iterator;

                KarmaBase.erase(karmabase_iterator);
                TimestampBase.erase(timestampbase_iterator);
                UserBase.erase(userbase_iterator);
                DataBase.erase(database_iterator);


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
                // const Record * record = iteration->second;
                if (callback(*iteration->second) == false)
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
                    std::cerr << "{" << pair.first << " : " << pair.second.record << "}";
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
