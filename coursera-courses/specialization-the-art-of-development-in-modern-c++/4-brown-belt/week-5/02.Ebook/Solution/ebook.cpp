#include <iomanip>
#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

class ReadingManager
{
public:
    ReadingManager() :
    people(MAX_USER_COUNT_ + 1, -1),
    pages(MAX_PAGE_COUNT_ + 1, 0) {}

    void Read(int user_id, int page_count)
    {
        for (int i = people[user_id] + 1; i <= page_count; i++)
        {
            ++pages[i];
        }
        people[user_id] = page_count;
    }

    double Cheer(int user_id) const
    {
        if (people[user_id] == -1)
        {
            return 0;
        }

        if (pages[0] == 1)
        {
            return 1;
        }
        return static_cast<double>(pages[0] - pages[people[user_id]]) / static_cast<double>(pages[0] - 1);
    }
private:
    static const int MAX_USER_COUNT_ = 100'000;
    static const int MAX_PAGE_COUNT_ = 1'000;

    std::vector<int> people;
    std::vector<int> pages;
};


int main() {
    // Для ускорения чтения данных отключается синхронизация
    // cin и cout с stdio,
    // а также выполняется отвязка cin от cout
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ReadingManager manager;

    int query_count;
    cin >> query_count;

    for (int query_id = 0; query_id < query_count; ++query_id) {
        string query_type;
        cin >> query_type;
        int user_id;
        cin >> user_id;

        if (query_type == "READ") {
            int page_count;
            cin >> page_count;
            manager.Read(user_id, page_count);
        } else if (query_type == "CHEER") {
            cout << setprecision(6) << manager.Cheer(user_id) << "\n";
        }
    }

    return 0;
}
