#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int first_set, second_set, couples_counter = 0;
    set<int> first_sequence;
    set<int> second_sequence;
    cin >> first_set;
    for (int i = 0; i < first_set; i++) {
        int elem;
        cin >> elem;
        first_sequence.insert(elem);
    }
    cin >> second_set;
    for (int i = 0; i < second_set; i++) {
        int elem;
        cin >> elem;
        second_sequence.insert(elem);
    }

    set<int> intersect;
    set_intersection(first_sequence.begin(), first_sequence.end(),
                     second_sequence.begin(), second_sequence.end(),
                     inserter(intersect, intersect.begin()));
    for (auto elem : intersect) {
        cout << elem << " ";
    }
    return 0;
}
