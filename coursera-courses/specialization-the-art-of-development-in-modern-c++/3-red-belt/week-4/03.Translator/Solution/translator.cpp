#include "test_runner.h"
#include <string>
#include <vector>
/*
#include <map>
*/

using namespace std;

class Translator {
public:
    Translator() = default;

    using Dictionary = map<string_view, string_view>;



    void Add(string_view source, string_view target) {
        const string_view smth = data.emplace_back(source);

        dict_forward[smth] = smth;
        cerr << dict_forward << endl;
    }

    string_view TranslateForward(string_view source) const {
        return  "";
    }

    string_view TranslateBackward(string_view target) const {
        return  "";
    }


private:
    Dictionary dict_forward;
    Dictionary dict_backward;
    deque<string> data;
};


void TestSimple() {
    Translator translator;
    translator.Add(string("okno"), string("window"));
    translator.Add(string("stol"), string("table"));

    ASSERT_EQUAL(translator.TranslateForward("okno"), "window");
    ASSERT_EQUAL(translator.TranslateBackward("table"), "stol");
    ASSERT_EQUAL(translator.TranslateBackward("stol"), "");
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestSimple);

    return 0;
}
