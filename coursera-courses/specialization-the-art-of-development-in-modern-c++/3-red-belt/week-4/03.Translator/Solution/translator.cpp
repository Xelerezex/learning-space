#include "test_runner.h"
#include <string>
#include <deque>
#include <map>


using namespace std;

class Translator {
    private:
        using Dictionary = map<string_view, string_view>;
        Dictionary dict_forward;
        Dictionary dict_backward;
        deque<string> data;

        string_view CopyStr(string_view target) {
            if (dict_forward.find(target) == dict_forward.end()) {
                return data.emplace_back(target);
            } else {
                return target;
            }

            if (dict_backward.find(target) == dict_backward.end()) {
                return data.emplace_back(target);
            } else {
                return target;
            }
        }

    public:
        Translator() = default;

        void Add(string_view source, string_view target) {
            const string_view source_copy = CopyStr(source);
            const string_view target_copy = CopyStr(target);

            dict_forward[source_copy]  = target_copy;
            dict_backward[target_copy] = source_copy;
            // cerr << dict_forward << endl;
            // cerr << data << endl;
        }


        string_view TranslateForward(string_view source) const {
            if (const auto it = dict_forward.find(source); it != dict_forward.end()) {
                return it->second;
            } else {
                return {};
            }
        }

        string_view TranslateBackward(string_view target) const {
            if (const auto it = dict_backward.find(target); it != dict_backward.end()) {
                return it->second;
            } else {
                return {};
            }
        }
};


void TestSimple() {
    Translator translator;
    translator.Add(string("okno"), string("win"));
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
