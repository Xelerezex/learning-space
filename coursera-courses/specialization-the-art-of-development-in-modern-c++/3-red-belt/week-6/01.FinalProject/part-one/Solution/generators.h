#pragma once
#include "headers.h"

//---------------------------------IMPLEMENTATION-----------------------------------------------//
template<typename T>
std::vector<T> generate_random_vector (
            size_t size,
            T min = std::numeric_limits<T>::min(),
            T max = std::numeric_limits<T>::max(),
            uint32_t seed = 0
);

std::string generate_random_word (
        const std::vector<uint32_t> &alphabet = {},
        const uint32_t word_length = 1,
        const uint32_t seed = 0
);

vector<std::string> generate_unique_words (
        const size_t unique_words = 1,
        const uint32_t word_length = 1,
        const bool flag_random_word_length = true,
        const std::vector<uint32_t> &alphabet = {}
);

std::string generate_random_document(
        std::vector<std::string> &words,
        const size_t words_in_one_doc = 1,
        const size_t seed = 69
);

std::vector<std::string> generate_random_documents (
        const size_t size = 1,
        const size_t words_in_one_doc = 1,
        const size_t unique_words = 1,
        const size_t word_length = 1,
        const size_t seed = 69
);
//----------------------------------------------------------------------------------------------//

//----------------------------GENERATE-RANDOM-CONTAINERS----------------------------------------//
template<typename T>
std::vector<T> generate_random_vector(size_t size, T min, T max, uint32_t seed)
{
    std::uniform_int_distribution<T> distribution(min, max);
    std::default_random_engine generator(seed);

    std::vector<T> data(size);
    std::generate(data.begin(), data.end(), [&]() { return distribution(generator); });
    return data;
}
//----------------------------------------------------------------------------------------------//
