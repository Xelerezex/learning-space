#include <list>
#include <string>
#include <algorithm>
#include "test_runner.h"
using namespace std;

class Editor {
     public:
        // Реализуйте конструктор по умолчанию и объявленные методы
        Editor() : CursorIt(Data.begin()) {}

        void Left() {
            if (CursorIt != Data.begin() && !Data.empty()) {
                advance(CursorIt, -1);
            }
        }
        void Right() {
            if (CursorIt != Data.end() && !Data.empty()) {
                advance(CursorIt, 1);
            }
        }

        void Insert(char token) {
            if (CursorIt == Data.end()) {
                Data.push_back(token);
            } else {
                Data.insert(CursorIt, token);
           }
        }
        void Paste() {
            CursorIt = Data.insert(CursorIt, Pool.begin(), Pool.end());

            for (size_t i = 0; i < Pool.size(); ++i) {
                Right();
            }
        }

        void Cut(size_t tokens = 1) {
            Pool.clear();

            for (size_t it = 0; it < tokens; ++it) {
                if (CursorIt != Data.end()) {
                    Pool.push_back(*CursorIt);
                    CursorIt = Data.erase(CursorIt);
                }
            }
        }

        void Copy(size_t tokens = 1) {
            Pool.clear();

            auto temporary = CursorIt;
            for (size_t it = 0; it < tokens; ++it) {
                if (temporary != Data.end()) {
                    Pool.push_back(*temporary);
                    advance(temporary, 1);
                }
            }
        }

        string GetText() const {
            string temporary;
            for(const auto &it : Data) {
                temporary.push_back(it);
            }
            // cerr << "   " << *prev(CursorIt) << " | " << *CursorIt << endl;
            return temporary;
        }

    private:
        list<char> Data, Pool;
        list<char>::iterator CursorIt;
};

void TypeText(Editor& editor, const string& text) {
    for(char c : text) {
        editor.Insert(c);
    }
}

void TestEditing() {
    {
        Editor editor;
        const size_t text_len = 12;
        const size_t first_part_len = 7;
        TypeText(editor, "hello, world");
        ASSERT_EQUAL(editor.GetText(), "hello, world");


        for(size_t i = 0; i < text_len; ++i) {
            editor.Left();
        }

        TypeText(editor, "");


        editor.Cut(first_part_len);                                // 1
        ASSERT_EQUAL(editor.GetText(), "world");

        for(size_t i = 0; i < text_len - first_part_len; ++i) {
            editor.Right();
        }

        TypeText(editor, ", ");
        ASSERT_EQUAL(editor.GetText(), "world, ");
        editor.Paste();                 // world, hello,

        editor.Left();
        editor.Left();
        editor.Cut(3);                                              // 2

        ASSERT_EQUAL(editor.GetText(), "world, hello");
    }
    {
        Editor editor;

        TypeText(editor, "misprnit");   // misprnit|
        editor.Left();                  // misprni|t
        editor.Left();                  // misprn|it
        editor.Left();                  // mispr|nit
        editor.Cut(1);                  // mispr|it
        editor.Right();                 // mispri|t
        editor.Paste();                 // misprin|t

        ASSERT_EQUAL(editor.GetText(), "misprint");
    }
}

void TestReverse() {
    Editor editor;

    const string text = "esreveR";
    for(char c : text) {
        editor.Insert(c);
        editor.Left();
    }

    ASSERT_EQUAL(editor.GetText(), "Reverse");
}


void TestNoText() {
    Editor editor;
    ASSERT_EQUAL(editor.GetText(), "");

    editor.Left();
    editor.Left();
    editor.Right();
    editor.Right();
    editor.Copy(0);
    editor.Cut(0);
    editor.Paste();

    ASSERT_EQUAL(editor.GetText(), "");
}


void TestEmptyBuffer() {
    Editor editor;

    editor.Paste();
    TypeText(editor, "example");
    editor.Left();
    editor.Left();
    editor.Paste();
    editor.Right();
    editor.Paste();
    editor.Copy(0);
    editor.Paste();
    editor.Left();
    editor.Cut(0);
    editor.Paste();

    ASSERT_EQUAL(editor.GetText(), "example");
}

void TestCopyPasteLastChars() {
    Editor editor;
    TypeText(editor, "happy birthday");
    editor.Left();
    editor.Left();
    editor.Copy(5);
    editor.Paste();
    ASSERT_EQUAL(editor.GetText(), "happy birthdayay");
}

void TestCut()
{
    Editor editor;
    //1
    editor.Cut(10);
    editor.Insert('a');
    editor.Left();
    //2
    editor.Cut(1);
    ASSERT_EQUAL(editor.GetText(), "");
    editor.Paste();
    ASSERT_EQUAL(editor.GetText(), "a");
    //3
    editor.Cut(0);
    editor.Paste();
    ASSERT_EQUAL(editor.GetText(), "a");
    TypeText(editor, "bcde");
    editor.Left(); editor.Left(); editor.Left(); editor.Left(); editor.Left();
    //4
    editor.Cut(10);
    ASSERT_EQUAL(editor.GetText(), "");
    editor.Paste();
    ASSERT_EQUAL(editor.GetText(), "abcde");
    editor.Left(); editor.Left(); editor.Left(); editor.Left(); editor.Left();
    //5
    editor.Cut(5);
    ASSERT_EQUAL(editor.GetText(), "");
    editor.Paste();
    //6
    editor.Left(); editor.Left(); editor.Left(); editor.Left(); editor.Left();
    editor.Cut(1);
    ASSERT_EQUAL(editor.GetText(), "bcde");
    editor.Right();
    editor.Cut(1);
    ASSERT_EQUAL(editor.GetText(), "bde");
    editor.Cut(1);
    editor.Cut(1);
    ASSERT_EQUAL(editor.GetText(), "b");
}

void TestCopy()
{
    Editor editor;
    //1
    editor.Copy(10);
    editor.Insert('a');                     // a|
    editor.Paste();
    editor.Left();
    ASSERT_EQUAL(editor.GetText(), "a");    // |a
    //2
    editor.Copy(1);
    editor.Paste();
    ASSERT_EQUAL(editor.GetText(), "aa");//between a  // a|a
    //3
    editor.Copy(0);
    editor.Paste();
    ASSERT_EQUAL(editor.GetText(), "aa");           // a|a
    TypeText(editor, "bcde");
    editor.Left(); editor.Left(); editor.Left(); editor.Left(); editor.Left(); editor.Left();
    //4
    editor.Cut(10);             // abcdea
    ASSERT_EQUAL(editor.GetText(), "");
    editor.Paste();
    ASSERT_EQUAL(editor.GetText(), "abcdea");
}

void UserTest()
{
    Editor editor;
    TypeText(editor, "1234567");    // 1234567|
    editor.Left();                  // 123456|7
    editor.Left();                  // 12345|67
    editor.Cut(1);                  // 12345|7 {6}
    editor.Paste();                 // 123456|7 {6}
    editor.Paste();                 // 1234566|7 {6}
    editor.Paste();                 // 12345666|7 {6}
    ASSERT_EQUAL(editor.GetText(), "123456667");
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestEditing);

    RUN_TEST(tr, TestReverse);

    RUN_TEST(tr, TestNoText);


    RUN_TEST(tr, TestEmptyBuffer);

    RUN_TEST(tr, TestCopyPasteLastChars);
    RUN_TEST(tr, TestCut);
    RUN_TEST(tr, TestCopy);
    RUN_TEST(tr, UserTest);

    return 0;
}
