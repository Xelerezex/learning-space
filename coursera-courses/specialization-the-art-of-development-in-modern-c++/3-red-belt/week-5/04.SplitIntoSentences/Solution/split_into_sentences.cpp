#include "test_runner.h"

#include <vector>
using namespace std;

// Объявляем Sentence<Token> для произвольного типа Token
// синонимом vector<Token>.
// Благодаря этому в качестве возвращаемого значения
// функции можно указать не малопонятный вектор векторов,
// а вектор предложений — vector<Sentence<Token>>.
template <typename Token>
using Sentence = vector<Token>;

// Класс Token имеет метод bool IsEndSentencePunctuation() const
template <typename Token>
vector<Sentence<Token>> SplitIntoSentences(vector<Token> tokens) {
    auto it = tokens.begin();

    size_t index = 0;
    vector<Sentence<Token>> sentences;

    sentences.push_back({});

    for (auto &item : tokens) {
        if(item.IsEndSentencePunctuation() &&
            ( !(*next(it)).IsEndSentencePunctuation() || next(it) == tokens.end()) ) {
            sentences[index++].push_back(move(item));

            if(next(it) != tokens.end()) {
                sentences.push_back({});
            }
        } else {
            sentences[index].push_back(move(item));
        }
        ++it;
    }

    return sentences;
}


struct TestToken {
    string data;
    bool is_end_sentence_punctuation = false;

    bool IsEndSentencePunctuation() const {
        return is_end_sentence_punctuation;
    }
    bool operator==(const TestToken& other) const {
        return data == other.data && is_end_sentence_punctuation == other.is_end_sentence_punctuation;
    }
};

ostream& operator<<(ostream& stream, const TestToken& token) {
    return stream << token.data;
}

// Тест содержит копирования объектов класса TestToken.
// Для проверки отсутствия копирований в функции SplitIntoSentences
// необходимо написать отдельный тест.
void TestSplitting() {
    ASSERT_EQUAL(
        SplitIntoSentences(vector<TestToken>({{"Split"}, {"into"}, {"sentences"}, {"!"}})),
        vector<Sentence<TestToken>>({
                {{"Split"}, {"into"}, {"sentences"}, {"!"}}
        })
    );

    ASSERT_EQUAL(
        SplitIntoSentences(vector<TestToken>({{"Split"}, {"into"}, {"sentences"}, {"!", true}})),
        vector<Sentence<TestToken>>({
                {{"Split"}, {"into"}, {"sentences"}, {"!", true}}
        })
    );

    ASSERT_EQUAL(
        SplitIntoSentences(vector<TestToken>({{"Split"}, {"into"}, {"sentences"}, {"!", true}, {"!", true}, {"Without"}, {"copies"}, {".", true}})),
        vector<Sentence<TestToken>>({
                {{"Split"}, {"into"}, {"sentences"}, {"!", true}, {"!", true}},
                {{"Without"}, {"copies"}, {".", true}},
        })
    );
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestSplitting);
    return 0;
}
