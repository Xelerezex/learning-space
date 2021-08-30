#include "test_runner.h"
#include "tests.h"

template<typename Type>
class Deque {
    public:
        Deque() {}
    private:
        vector<Type> Front;
        vector<Type> Back;
};

int main() {
    TestAll();

    return 0;
}
