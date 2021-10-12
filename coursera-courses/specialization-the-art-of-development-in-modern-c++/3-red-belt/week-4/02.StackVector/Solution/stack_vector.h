#pragma once

#include <stdexcept>
using namespace std;

template <typename T, size_t N>
class StackVector {
public:
    // StackVector() : __Size{0} {};
    explicit StackVector(size_t a_size = 0) : __Size( [a_size]{
        if (a_size > N) {
            throw invalid_argument("");
        } else {
            return a_size;
        }
    }() ){}

    T& operator[](size_t index) { return Data[index]; }
    const T& operator[](size_t index) const { return Data[index]; }

    auto begin() { return Data; };
    auto end()   { return Data + __Size; };
    auto begin() const { return Data; };
    auto end() const   { return Data + __Size; }


    size_t Size() const     { return __Size; }
    size_t Capacity() const { return N; }

    void PushBack(const T& value) {
        if (__Size == N){
            throw overflow_error("");
        } else {
            Data[__Size] = value;
            ++__Size;
        }
    }

    T PopBack() {
        if (__Size == 0) {
            throw underflow_error("");
        } else {
            T res = Data[__Size - 1];
            Data[__Size - 1] = 0;
            --__Size;
            return res;
        }
    }

private:
    T Data[N];
    size_t __Size;
};

