#pragma once

#include <cstdlib>
#include <iostream>

// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
    SimpleVector() : Data(new T[0]), SizeVal(0), CapacityVal(SizeVal * 2) {
    }

    explicit SimpleVector(size_t size) : Data(new T[size]), SizeVal(size), CapacityVal(size){
    }


    T& operator[](size_t index) {
        return *(Data + index);
    }


    T* begin() {
        return Data;
    }

    T* end() {
        return Data + SizeVal;
    }

    size_t Size() const {
        return SizeVal;
    }

    size_t Capacity() const {
        return CapacityVal;
    }

    void PushBack(const T& value) {
        bool cond1 = (CapacityVal == 0 && SizeVal == 0);
        bool cond2 = (SizeVal == CapacityVal);
        bool cond3 = (SizeVal < CapacityVal);


        if (cond1) {
            Data[0] = value;
            ++CapacityVal;
            ++SizeVal;

            // std::cerr << "First" << std::endl;

        } else if (!cond1 && cond2) {
            // New Capacity
            T* temporary = new T[SizeVal + 1];
            CapacityVal *=  2;

            for (int it = 0; it < SizeVal; ++it) {
                temporary[it] = Data[it];
            }

            temporary[SizeVal] = value;
            ++SizeVal;

            delete[] Data;

            Data = new T[CapacityVal];
            for (int it = 0; it < SizeVal; ++it) {
                Data[it] = temporary[it];
            }

            // Cleaning temporary massive
            delete[] temporary;

            // std::cerr << "Second" << std::endl;

        } else if (!cond1 && cond3) {
            Data[SizeVal] = value;
            ++SizeVal;

            // std::cerr << "Third" << std::endl;
        }
    }

    ~SimpleVector() {
        delete[] Data;
    }

private:
    T* Data;
    size_t SizeVal;
    size_t CapacityVal;
};
