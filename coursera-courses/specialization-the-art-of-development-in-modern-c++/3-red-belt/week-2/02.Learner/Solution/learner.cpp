#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

class Learner {
    private:
        vector<string> dict;

    public:
        set<string> unique_val;

        int Learn(const vector<string>& words) {
            int newWords = 0;


            for (const auto& word : words) {

                auto pairistrue = unique_val.insert(word);

                if (pairistrue.second) {
                    dict.push_back(*pairistrue.first);
/*                    insert_sorted(dict, *pairistrue.first);*/
                    ++newWords;
                }
            }
            return newWords;
        }

        vector<string> KnownWords() {
            sort(dict.begin(), dict.end());
    /*        dict.erase(unique(dict.begin(), dict.end()), dict.end());*/
            return dict;
        }
};
