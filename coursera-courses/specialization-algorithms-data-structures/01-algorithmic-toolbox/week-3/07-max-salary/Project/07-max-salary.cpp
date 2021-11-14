#include "test_runner.h"
#include "profile.h"

bool IsGreaterOrEqual(string &str1, string &str2) {
    return stoi(str1 + str2) > stoi(str2 + str1);
}

string largest_number(vector<string> &strings) {
    sort(strings.begin(), strings.end(),
        [](string str1, string str2){
            //cerr << str1 << " : " << str2 << endl;
            return IsGreaterOrEqual(str1, str2);
        }
    );
    stringstream result;
    for (auto iter = strings.begin(); iter != strings.end(); ++iter) {
        result << *iter;
    }

  return result.str();
}

int main() {
    {
        vector<string> input = {
            "21", "2"
        };
        string expected = "221";
        LOG_DURATION("First Test");
        ASSERT_EQUAL(largest_number(input), expected);
    }
    {
        vector<string> input = {
            "9", "4", "6", "1", "9"
        };
        string expected = "99641";
        LOG_DURATION("Second Test");
        ASSERT_EQUAL(largest_number(input), expected);
    }
    {
        vector<string> input = {
            "23", "39", "92"
        };
        string expected = "923923";
        LOG_DURATION("Third Test");
        ASSERT_EQUAL(largest_number(input), expected);
    }
    {
       vector<string> input = {
             "2", "8", "2", "3", "6", "4", "1", "1", "10", "6", "11", "3", "3", "6", "1",
             "3", "8", "4", "6", "1", "10", "8", "4", "10", "4", "1", "3", "2", "3",
             "2", "6", "1", "5", "2", "9", "8", "5", "10", "8", "7", "9", "6", "4",
             "2", "6", "3", "8", "8", "9", "8", "999", "2", "9", "10", "3", "10", "7", "5",
             "7", "1", "7", "5", "1", "4", "7", "6", "1", "10", "5", "4", "8", "4", "2",
             "7", "8", "1", "1", "7", "4", "1", "1", "9", "8", "6", "5", "9", "9", "3",
             "7", "6", "3", "10", "8", "10", "7", "2", "5", "1", "1", "9", "9", "5"
        };
        string expected = "999999999999888888888888777777777666666666655555555444444444333333333322222222211111111111111111101010101010101010";
        LOG_DURATION("Fourth Test");
        ASSERT_EQUAL(largest_number(input), expected);
    }
}
