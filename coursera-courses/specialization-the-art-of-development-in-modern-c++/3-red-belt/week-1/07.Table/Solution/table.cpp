#include "test_runner.h"

using namespace std;

// Реализуйте здесь шаблонный класс Table
template<typename T>
class Table {
    public:
        Table(const size_t columns, const size_t rows) : Columns(columns), Rows(rows) {
            if (columns == 0 || rows == 0) {
                Resize(0, 0);
            } else {
                Resize(columns, rows);
            }
        }

        void Resize(const size_t cols, const size_t rows) {
            Columns = cols;
            Rows = rows;

            TableData.resize(cols);

            for (auto& item : TableData) {
                item.resize(rows);
            }
        }

        pair<size_t, size_t> Size() const {
            return make_pair(Columns, Rows);
        }

        vector<T>& operator [] (const size_t& item) { return TableData[item]; }
        const vector<T>& operator [] (const size_t& item) const { return TableData[item]; }

    private:
        vector<vector<T>> TableData;
        size_t Columns, Rows;
};


void TestTable() {
    Table<int> t(1, 1);
    ASSERT_EQUAL(t.Size().first, 1u);
    ASSERT_EQUAL(t.Size().second, 1u);
    t[0][0] = 42;
    ASSERT_EQUAL(t[0][0], 42);
    t.Resize(3, 4);
    ASSERT_EQUAL(t.Size().first, 3u);
    ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestTable);

/*    Table<int> t(5, 6);

    t[1][1] = 7;
    t[2] = {1, 2, 3};

    vector<int> z = {0, 1, 2, 3, 4, 5, 6};
    z.resize(4);

    cout << t[1][1] << endl;
    cout << t[2][2] << endl;
    cout << z << endl;
*/
    return 0;
}
