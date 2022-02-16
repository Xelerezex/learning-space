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
            auto iter = DataSet.insert({record, (++count_data)});

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
        void RangeByTimestamp(int low, int high, Callback callback) const {}*/

        // Analog: Count in diapasone
        // Goes from [low, high] of karma, call callback, if callback == false, stop iteration
/*        template <typename Callback>
        void RangeByKarma(int low, int high, Callback callback) const {}*/

        // Analog: Count in diapasone
        // Goes from [low, high] of user, call callback, if callback == false, stop iteration
/*        template <typename Callback>
        void AllByUser(const string& user, Callback callback) const {}*/


        auto begin() const { return DataSet.begin(); }
        auto end()   const { return DataSet.end(); }
    private:
        size_t count_data = 0;
        multimap<Record, size_t/*, RecordHasher*/> DataSet;
        unordered_map<string, typename multimap<Record, size_t>::iterator, RecordHasher> RefData;
};

ostream& operator << (ostream& os, Database DataSet)
{
    os << "[";
    bool first = true;

    for(const auto &[ref, sz] : DataSet)
    {
        if (!first)
        {
            os << ", ";
        }
        first = false;
        os << sz            << " : ("
           << ref.id        << ", "
           << ref.title     << ", "
           << ref.user      << ", "
           << ref.timestamp << ", "
           << ref.karma     << ")";
    }
    return os << "]";
}

void TestRangeBoundaries()
{
    const int good_karma = 1000;
    const int bad_karma = -10;

    Database db;
    ASSERT(db.Put({"id1", "Hello there", "master", 1536107260, good_karma}));
    ASSERT(db.Put({"id2", "O>>-<", "general2", 1536107260, bad_karma}));

    std::cerr << db << std::endl;

    /*
    int count = 0;
    db.RangeByKarma(
        bad_karma,
        good_karma,
        [&count] (const Record&) {
            ++count;
            return true;
    });

    ASSERT_EQUAL(2, count);
    */
}
/*
void TestSameUser()
{
    Database db;
    db.Put({"id1", "Don't sell", "master", 1536107260, 1000});
    db.Put({"id2", "Rethink life", "master", 1536107260, 2000});

    int count = 0;
    db.AllByUser(
        "master",
        [&count] (const Record&) {
            ++count;
            return true;
    });

    ASSERT_EQUAL(2, count);
}
*/
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
    /*
    RUN_TEST(tr, TestSameUser);
    RUN_TEST(tr, TestReplacement);
    */
    return 0;
}
