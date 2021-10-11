/*#include "test_runner.h"
#include "profile.h"
*/
#include <algorithm>
#include <iostream>
#include <sstream>
#include <list>
#include <map>

using namespace std;

class Athlets {
    public:
        void Add(const unsigned number, const unsigned after) {
            if (athlets.empty()){
                auto it_to_at = athlets.emplace(begin(athlets), number);
                map_with_links[number] = it_to_at;
            } else if (const auto it = map_with_links.find(after);it != end(map_with_links)) {
                auto it_to_at = athlets.emplace(it->second, number);
                map_with_links[number] = it_to_at;
            } else {
                auto it_to_at = athlets.emplace(end(athlets), number);
                map_with_links[number] = it_to_at;
            }
        }

        void Print() const {
            for (const auto &item : athlets) {
                cout << item << '\n';
            }
        }
        ostream& Print(ostringstream& os) const {
            for (const auto &item : athlets) {
                os << item << '\n';
            }
            return os;
        }
    private:
        list<unsigned> athlets;
        map<unsigned, list<unsigned>::iterator> map_with_links;
};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

/*    {
        Athlets athlets;
        vector<pair<unsigned, unsigned>> input = {{42, 0}, {17, 42}, {13, 0}, {123, 42}, {5, 13}};
        ostringstream expected("17\n123\n42\n5\n13\n"), os;

        LOG_DURATION("Coursera example");
        for (const auto &pair : input) {
            athlets.Add(pair.first, pair.second);
        }
        athlets.Print(os);
        ASSERT_EQUAL(os.str(), expected.str());
    }*/
    {
        Athlets athlets;
        int quantity = 0;
        cin >> quantity;

        for (int it = 0; it < quantity; ++it) {
            unsigned number = 0, previous = 0;
            cin >> number >> previous;
            athlets.Add(number, previous);
        }

        athlets.Print();
    }

}
