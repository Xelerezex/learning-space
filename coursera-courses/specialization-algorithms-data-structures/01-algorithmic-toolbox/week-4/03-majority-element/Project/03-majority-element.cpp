#include "test_runner.h"
#include "profile.h"
#include "random_generate.h"

int get_majority_element(vector<int> &input) {
    map<int, int> hash;

    for (auto &item : input) {
        if (auto it = hash.find(item); it == hash.end()) {
            hash[item] = 1;
        } else {
            hash[item] += 1;
        }
    }

    int maxn = max_element(hash.begin(), hash.end(),
        [] (pair<int, int> lhs, pair<int, int> rhs) {
            return lhs.second < rhs.second;
        }
    )->second;

    // cerr << hash << endl;
    return ((input.size() / 2) < maxn) ? 1 : 0 ;
}

int main() {
    {
        vector<int> input = {
            2, 3, 9, 2, 2,
        };

        LOG_DURATION("Test #1");
        ASSERT_EQUAL(get_majority_element(input), 1);
    }
    {
        vector<int> input = {
            1, 2, 3, 4,
        };

        LOG_DURATION("Test #2");
        ASSERT_EQUAL(get_majority_element(input), 0);
    }
    {

        vector<int> temp_rand = generate_random_vector(49'999, 0, 1'000'000'000, 420);
        vector <int> temp(50'001, 1'000'000'000);
        vector<int> input;

        for (size_t it = 0; it < 50'002; ++it) {
            input.push_back(move(*(--temp_rand.end())));
            input.push_back(move(*(--temp.end())));
            temp_rand.pop_back();
            temp.pop_back();
        }

        LOG_DURATION("Test #3");
        ASSERT_EQUAL(get_majority_element(input), 0);
    }
}
