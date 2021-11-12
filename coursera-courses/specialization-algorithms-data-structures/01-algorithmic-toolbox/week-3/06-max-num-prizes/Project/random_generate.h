#pragma once
#include "headers.h"

template<typename T>
std::vector<T> generate_random_vector(size_t size,
                                  T min = std::numeric_limits<T>::min(),
                                  T max = std::numeric_limits<T>::max(),
                                  uint32_t seed = 0);
template<typename T>
std::vector<T> generate_random_vector(size_t size, T min, T max, uint32_t seed) {
    std::uniform_int_distribution<T> distribution(min, max);
    std::default_random_engine generator(seed);

    std::vector<T> data(size);
    std::generate(data.begin(), data.end(), [&]() { return distribution(generator); });
    return data;
}
