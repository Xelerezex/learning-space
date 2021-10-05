#include "test_runner.h"

#include <algorithm>
#include <numeric>
using namespace std;

template <typename T>
void Swap(T* first, T* second) {
    T temporary = *first;
    *first = *second;
    *second = temporary;
}


template<typename P>
int partition(vector<P*> &array, int &start, int &end) {
    int iteration = start + 1; //next element after start
    P pivot = *array[start];

    for (int it = iteration; it <= end; ++it){
        if (*array[it] < pivot) {
            Swap(array[iteration], array[it]);
            ++iteration;
        }
    }

    Swap(array[start], array[iteration - 1]);

    return iteration - 1;
}


template<typename T>
void quicksort(vector<T*> &array, int start, int end) {
    if (start < end) {
        int pivot = partition(array, start, end);
        quicksort(array, start, (pivot - 1));
        quicksort(array, (pivot + 1), end);
    }
}


template <typename T>
void SortPointers(vector<T*>& pointers) {
    int first = 0,
        last  = pointers.size() - 1;
    quicksort(pointers, first, last);
}


template <typename T>
void ReversedCopy(T* source, size_t count, T* destination) {
    size_t last = count - 1;
    T* temporary = new T[count];

    // Copying *count* elements in temporary
    for (size_t it = 0; it < count; ++it) {
        temporary[it] = *(source + last);
        --last;
    }

    for (size_t it = 0; it < count; ++it) {
        destination[it] = temporary[it];
    }

    delete[] temporary;
}

void TestSwap() {
    int a = 1;
    int b = 2;
    Swap(&a, &b);
    ASSERT_EQUAL(a, 2);
    ASSERT_EQUAL(b, 1);

    string h = "world";
    string w = "hello";
    Swap(&h, &w);
    ASSERT_EQUAL(h, "hello");
    ASSERT_EQUAL(w, "world");

    double z = 3.14;
    double x = 2.17;
    Swap(&z, &x);
    ASSERT_EQUAL(z, 2.17);
    ASSERT_EQUAL(x, 3.14);

}


void TestSortPointers() {
    int one = 1;
    int two = 2;
    int three = 3;

    vector<int*> pointers;
    pointers.push_back(&two);
    pointers.push_back(&three);
    pointers.push_back(&one);

    SortPointers(pointers);

    ASSERT_EQUAL(pointers.size(), 3u);
    ASSERT_EQUAL(*pointers[0], 1);
    ASSERT_EQUAL(*pointers[1], 2);
    ASSERT_EQUAL(*pointers[2], 3);

    string first  = "A";
    string second = "B";
    string third  = "C";
    string fourth = "D";


    vector<string*> pointers_str;
    pointers_str.push_back(&fourth);
    pointers_str.push_back(&first);
    pointers_str.push_back(&third);
    pointers_str.push_back(&second);

    SortPointers(pointers_str);

    ASSERT_EQUAL(pointers_str.size(), 4u);
    ASSERT_EQUAL(*pointers_str[0], "A");
    ASSERT_EQUAL(*pointers_str[1], "B");
    ASSERT_EQUAL(*pointers_str[2], "C");
    ASSERT_EQUAL(*pointers_str[3], "D");
}


void TestReverseCopy() {
    const size_t count = 7;

    int* source = new int[count];
    int* dest = new int[count];

    for (size_t i = 0; i < count; ++i) {    // source = {1, 2, 3, 4, 5, 6, 7}
        source[i] = i + 1;
    }

    ReversedCopy(source, count, dest);
    const vector<int> expected1 = {7, 6, 5, 4, 3, 2, 1};
    ASSERT_EQUAL(vector<int>(dest, dest + count), expected1);

    // Области памяти могут перекрываться
    ReversedCopy(source, count - 1, source + 1);
    const vector<int> expected2 = {1, 6, 5, 4, 3, 2, 1};
    ASSERT_EQUAL(vector<int>(source, source + count), expected2);

    delete[] dest;
    delete[] source;
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestSwap);
    RUN_TEST(tr, TestSortPointers);
    RUN_TEST(tr, TestReverseCopy);

    return 0;
}
