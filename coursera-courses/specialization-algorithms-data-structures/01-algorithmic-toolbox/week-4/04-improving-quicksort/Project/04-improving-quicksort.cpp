#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

template<typename S>
void Swap(S &first, S &second) {
    S temp = first;
    first = second;
    second = temp;
}

template<typename P>
int partition(vector<P> &array, int &start, int &end) {
    int iteration = start + 1; //next element after start
    P pivot = array[start];

    for (int it = iteration; it <= end; ++it){
        if (array[it] < pivot) {
            Swap(array[iteration], array[it]);
            ++iteration;
        }
    }

    Swap(array[start], array[iteration - 1]);

    return iteration - 1;

}



template<typename T>
void randomized_quick_sort(vector<T> &array, int start, int end) {
    if (start < end) {
        int random = start + rand( ) % (end - start + 1) ;
        Swap(array[random] , array[start]);        //swap pivot with 1st element.

        int pivot = partition(array, start, end);

        randomized_quick_sort(array, start, (pivot - 1));
        randomized_quick_sort(array, (pivot + 1), end);
    }
}


int main() {
    {
        std::vector<int> RandomVector = generate_data<int>(100'000'000, -100'000, 100'000);
        //cout << RandomVector << endl;
        std::vector<int> RandomSortedVector(begin(RandomVector), end(RandomVector));
        sort(begin(RandomSortedVector), end(RandomSortedVector));

        {
            LOG_DURATION("Quicksort (random partial) of 100'000'000");
            SortContainer(RandomVector, true);
        }

        ASSERT_EQUAL(RandomVector, RandomSortedVector);
    }
    {
        std::vector<int> RandomVector = generate_data<int>(100'000'000, -100'000, 100'000);
        //cout << RandomVector << endl;
        std::vector<int> RandomSortedVector(begin(RandomVector), end(RandomVector));
        sort(begin(RandomSortedVector), end(RandomSortedVector));       // Quicksort (random partial) of 100'000: 15722 ms

        {
            LOG_DURATION("Quicksort (first element partial) of 100'000'000");
            SortContainer(RandomVector, false);                         // Quicksort (first element partial) of 100'000: 14790 ms
        }

        ASSERT_EQUAL(RandomVector, RandomSortedVector);
    }
}
