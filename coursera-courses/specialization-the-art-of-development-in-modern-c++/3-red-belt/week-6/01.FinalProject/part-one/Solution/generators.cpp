#include "generators.h"

//----------------------------------------------------------------------------------------------//
std::string generate_random_word(
        const std::vector<uint32_t> &alphabet,
        const uint32_t word_length,
        const uint32_t seed
)
{
    std::string word(word_length, 0);

    std::uniform_int_distribution<size_t> distribution (
            0,
            alphabet.size()
    );
    std::default_random_engine generator(seed);

    std::generate(
        word.begin(),
        word.end(),
        [&]() {
            return alphabet[distribution(generator)];
    });

    return word;
}
//----------------------------------------------------------------------------------------------//

//----------------------------------------------------------------------------------------------//
vector<std::string> generate_unique_words(
        const size_t unique_words,
        const uint32_t word_length,
        const bool flag_random_word_length,
        const std::vector<uint32_t> &alphabet
)
{
    std::vector<std::string> output;
    for (size_t iter = 0; iter < unique_words; ++iter)
    {
        output.push_back (
            generate_random_word(
                alphabet,
                (flag_random_word_length) ? (rand() % word_length) : (word_length),
                rand()
            )
        );
    }
    return output;
}
//----------------------------------------------------------------------------------------------//

//----------------------------------------------------------------------------------------------//
std::string generate_random_document(
        std::vector<std::string> &words,
        const size_t words_in_one_doc,
        const size_t seed
)
{
    std::vector<std::string> output(words_in_one_doc);

    std::uniform_int_distribution<size_t> distribution (
            0,
            words.size()
    );
    std::default_random_engine generator(seed);

    std::generate(
        output.begin(),
        output.end(),
        [&] () {
            return words[distribution(generator)];
    });
    int z = 0;
    std::string oo;
    for (const auto &i : output)
    {
        oo += i + " ";
        ++z;
    }
    return oo;
}
//----------------------------------------------------------------------------------------------//

//----------------------------------------------------------------------------------------------//
std::vector<std::string> generate_random_documents (
        const size_t size,
        const size_t words_in_one_doc,
        const size_t unique_words,
        const size_t word_length,
        const size_t seed
)
{
    std::vector<string> output;

    const std::vector<std::vector<uint32_t>> alphabets {
        // 0 is {0...9}
        {48, 49, 50, 51, 52, 53, 54, 55, 56, 57},
        // 1 is {A...Z}
        {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90},
        // 2 is {a...z}
        {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122},
        // 3 is {0...9A...Za...z}
        {48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122},

    };

    std::vector<std::string> words = generate_unique_words(unique_words, word_length, true, alphabets[2]);
    // std::cerr << words << std::endl << words.size() << std::endl;

    for (size_t iteration = 0; iteration < size; ++iteration)
    {
        output.push_back (
            generate_random_document(words, words_in_one_doc, (seed + iteration))
        );
    }

    return output;
}
//----------------------------------------------------------------------------------------------//


