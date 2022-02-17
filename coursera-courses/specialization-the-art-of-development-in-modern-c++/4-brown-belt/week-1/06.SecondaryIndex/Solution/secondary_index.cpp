#include "test_runner.h"

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


struct RecordRef
{
    typename multimap<string, string>::iterator title_iterator;
    typename multimap<string, string>::iterator user_iterator;
    typename multimap<int, string>::iterator    timestamp_iterator;
    typename multimap<int, string>::iterator    karma_iterator;

    bool operator== (const RecordRef &other) const
    {
        return (*title_iterator == *other.title_iterator)
            && (*user_iterator == *other.user_iterator)
            && (*timestamp_iterator == *other.timestamp_iterator)
            && (*karma_iterator == *other.karma_iterator);
    }

    bool operator< (const RecordRef &other) const
    {
        return (*title_iterator < *other.title_iterator)
            && (*user_iterator < *other.user_iterator)
            && (*timestamp_iterator < *other.timestamp_iterator)
            && (*karma_iterator < *other.karma_iterator);
    }
};

struct RecordHasher
{
/*    size_t operator() (const Record& address) const
    {
        const size_t coef = 31;

        const hash<string> id_hasher;
        const hash<string> title_hasher;
        const hash<string> user_hasher;
        const hash<int>    timestamp_hasher;
        const hash<int>    karma_hasher;

        return (coef * coef * coef * coef * id_hasher(address.id))
             + (coef * coef * coef * title_hasher(address.title))
             + (coef * coef * user_hasher(address.user))
             + (coef * timestamp_hasher(address.timestamp))
             + (karma_hasher(address.karma));
    }*/
    size_t operator() (const string &str) const
    {
        const size_t coef = 2213;
        const hash<string> id_hasher;
        return coef * id_hasher(str);
    }
};

// Реализуйте этот класс
class Database
{

    public:
        // Database() {}
        // True, if insertion is successfull, else false
        bool Put(const Record& record)
        {
            auto iter = RefData.find(record.id);

            auto iter_to_title     = TitleData.insert({record.title, record.id});
            auto iter_to_user      = UserData.insert({record.user, record.id});
            auto iter_to_timestamp = TimestampData.insert({record.timestamp, record.id});
            auto iter_to_karma     = KarmaData.insert({record.karma, record.id});

            if (   iter          == RefData.end()
                && iter_to_title != TitleData.end()
                && iter_to_title != TitleData.end()
                && iter_to_title != TitleData.end()
                && iter_to_title != TitleData.end())
            {
                auto iter = DataSet.insert({record, RecordRef{iter_to_title, iter_to_user, iter_to_timestamp, iter_to_karma}});

                if (iter != DataSet.end())
                {
                    RefData.insert({record.id, iter});
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }

        // Find obj by id, return nullptr if there is no object
        const Record* GetById(const string& id) const
        {
            auto iter = RefData.find(id);

            if (iter != RefData.end())
            {
                auto iter_to_multi = (*iter).second;
                return &(*iter_to_multi).first;
            }
            else
            {
                return nullptr;
            }
        }

        // Find than delete obj, if there is no obj return false
        bool Erase(const string& id)
        {
            auto iter = RefData.find(id);

            if (iter != RefData.end())
            {
                auto iter_to_multi = (*iter).second;

                TitleData.erase(iter_to_multi->second.title_iterator);
                UserData.erase(iter_to_multi->second.user_iterator);
                TimestampData.erase(iter_to_multi->second.timestamp_iterator);
                KarmaData.erase(iter_to_multi->second.karma_iterator);

                DataSet.erase(iter_to_multi);
                RefData.erase(iter);

                return true;
            }
            else
            {
                return false;
            }
        }

        // Analog: Count in diapasone
        // Goes from [low, high] of timestamp, call callback, if callback == false, stop iteration
/*        template <typename Callback>
        void RangeByTimestamp(int low, int high, Callback callback) const
        {
        }*/

        // Analog: Count in diapasone
        // Goes from [low, high] of karma, call callback, if callback == false, stop iteration
        template <typename Callback>
        void RangeByKarma(int low, int high, Callback callback) const
        {
            auto low_iter = KarmaData.lower_bound(low);
            auto high_iter = KarmaData.lower_bound(high);

            auto db_low_iter = RefData.find(low_iter->second);
            auto db_high_iter = RefData.find(high_iter->second);

            for (auto iteration = db_low_iter->second; iteration != db_high_iter->second;)
            {
                if (callback((*iteration).first) == false)
                {
                    iteration = db_high_iter->second;
                }
                else
                {
                    ++iteration;
                }
            }

        }

        // Analog: Count in diapasone
        // Goes from [low, high] of user, call callback, if callback == false, stop iteration
        template <typename Callback>
        void AllByUser(const string& user, Callback callback) const
        {
            auto user_start = UserData.lower_bound(user);

            auto db_user_start = RefData.find(user_start->second);

            auto iteration = db_user_start->second;


            while (callback((*iteration).first) == true && iteration != DataSet.end())
            {
                iteration++;
            }
        }


        auto begin() const { return DataSet.begin(); }
        auto end()   const { return DataSet.end(); }
        void Print() const
        {
            std::cerr << std::endl;

            std::cerr << "TitleData" << " : " << std::endl
                      << TitleData << std::endl;
            std::cerr << "UserData" << " : " << std::endl
                      << UserData << std::endl;
            std::cerr << "TimestampData" << " : " << std::endl
                      << TimestampData << std::endl;
            std::cerr << "KarmaData" << " : " << std::endl
                      << KarmaData << std::endl;

            std::cerr << "[";
            bool first = true;
            for(const auto &pair : DataSet)
            {
                if (!first)
                {
                    std::cerr << ", ";
                }
                first = false;
                std::cerr << "("
                   << pair.first.id        << ", "
                   << pair.first.title     << ", "
                   << pair.first.user      << ", "
                   << pair.first.timestamp << ", "
                   << pair.first.karma     << ")";
            }
            std::cerr << "]";
            std::cerr << std::endl;
        }

    private:
        multimap<string, string> TitleData;
        multimap<string, string> UserData;
        multimap<int, string> TimestampData;
        multimap<int, string> KarmaData;
        multimap<Record, RecordRef> DataSet;
        unordered_map<string, typename multimap<Record, RecordRef>::iterator, RecordHasher> RefData;
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

void TestRangeBoundaries()
{
    const int good_karma = 1000;
    const int bad_karma = -10;

    Database db;
    ASSERT(db.Put({"id1", "Hello there", "master", 1536107260, good_karma}));
    ASSERT(db.Put({"id2", "O>>-<", "general2", 1536107260, bad_karma}));
    ASSERT(db.Put({"id7", "WIoFLY", "somebody", 1536107260, 500}));
    ASSERT(!db.Put({"id7", "WIoFLY", "somebody", 1536107260, 500}));

    // std::cerr << *db.GetById("id10") << std::endl;
    ASSERT_EQUAL(*db.GetById("id7"), (Record{"id7", "WIoFLY", "somebody", 1536107260, 500}));
    ASSERT_EQUAL(db.GetById("id10"), nullptr);
    ASSERT(db.Erase("id7"));
    ASSERT(!db.Erase("id7"));
    db.Print();


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

    db.Print();


    int count = 0;
    db.AllByUser(
        "master",
        [&count] (const Record&) {
            ++count;
            return true;
    });

    ASSERT_EQUAL(2, count);
}

/*
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
*/
int main()
{
    TestRunner tr;
    RUN_TEST(tr, TestRangeBoundaries);
    RUN_TEST(tr, TestSameUser);
    /*
    RUN_TEST(tr, TestReplacement);
    */
    return 0;
}
