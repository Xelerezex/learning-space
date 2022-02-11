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
};
// operator() for vector

// Реализуйте этот класс
class Database
{
public:
    // True, if insertion is successfull, else false
    bool Put(const Record& record);

    // Find obj by id, return nullptr if there is no object
    const Record* GetById(const string& id) const;

    // Find than delete obj, if there is no obj return false
    bool Erase(const string& id);

    // Analog: Count in diapasone
    // Goes from [low, high] of timestamp, call callback, if callback == false, stop iteration
    template <typename Callback>
    void RangeByTimestamp(int low, int high, Callback callback) const;

    // Analog: Count in diapasone
    // Goes from [low, high] of karma, call callback, if callback == false, stop iteration
    template <typename Callback>
    void RangeByKarma(int low, int high, Callback callback) const;

    // Analog: Count in diapasone
    // Goes from [low, high] of user, call callback, if callback == false, stop iteration
    template <typename Callback>
    void AllByUser(const string& user, Callback callback) const;
};

void TestRangeBoundaries()
{
    const int good_karma = 1000;
    const int bad_karma = -10;

    Database db;
    db.Put({"id1", "Hello there", "master", 1536107260, good_karma});
    db.Put({"id2", "O>>-<", "general2", 1536107260, bad_karma});

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
