#include "test_runner.h"
#include "profile.h"

class Athlets {
    public:
        void Add(const unsigned number, const unsigned previous) {

        }

        void Print() const {
            for (const auto &item : athlets) {
                cout << item << '\n';
            }
        }
    private:
        list<unsigned> athlets;
};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Athlets athlets;
    int quantity = 0;
    cin >> quantity;

    for (int it = 0; it < quantity; ++it) {
        unsigned number = 0, previous = 0;
        cin >> number >> previous;
        athlets.Add(number, previous);
    }

    athlets.Print();
}
