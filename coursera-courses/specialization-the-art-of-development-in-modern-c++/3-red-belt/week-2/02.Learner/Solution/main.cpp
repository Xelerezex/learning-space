#include "learner.h"
#include "test_runner.h"
#include "profile.h"


int main() {
    Learner learner;
    string line;
    ifstream in("words-1.txt");
    while (getline(in, line)) {
        vector<string> words;
        stringstream ss(line);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        {
            LOG_DURATION("Method Learn()");
            cout << learner.Learn(words) << "\n";
        }
    }

    cout << "=== known words ===\n";

    {
        LOG_DURATION("Method KnownWords()")

        for (auto word : learner.KnownWords()) {
            ostringstream os;
            cout << word << "\n";
        }
    }
}
