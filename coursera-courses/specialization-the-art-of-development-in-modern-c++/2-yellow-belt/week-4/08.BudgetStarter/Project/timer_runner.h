#pragma once
#include <chrono>
#include <iostream>

using namespace std::chrono;
using namespace std;

class Timer{
    public:
        template <class TimerFunc>
        void funcTimer(TimerFunc func, const string&);
    private:
};

template <class TimerFunc>
void Timer::funcTimer(TimerFunc func, const string& message){

    auto start = high_resolution_clock::now();
    func();
    auto stop = high_resolution_clock::now();

    cerr << message << ": "
        << duration_cast<microseconds>(stop - start).count() << " microseconds"
        << " (" << duration_cast<seconds>(stop - start).count() << " seconds)!" << endl;
}
