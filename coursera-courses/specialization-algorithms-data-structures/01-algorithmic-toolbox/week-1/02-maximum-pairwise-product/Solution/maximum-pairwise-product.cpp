#include <iostream>
#include <vector>


using namespace std;


long long int MaximumPairwiseProduct(vector<int> &data) {
    long long int first = 0, second = 0;
    auto iter_first = data.begin();

    for (auto iter = data.begin(); iter != data.end(); ++iter) {
        if (first <= *iter) {
            first = *iter;
            iter_first = iter;
        }
    }

    for (auto iter = data.begin(); iter != data.end(); ++iter) {
        if (second <= *iter && iter != iter_first) {
            second = *iter;
        }
    }

    return first * second;
}


int main() {
    int quantity = 0;
    cin >> quantity;
    vector<int> vect;

    for (int iter = 0; iter < quantity; ++iter) {
        int temp;
        cin >> temp;
        vect.push_back(temp);
    }

    cout << MaximumPairwiseProduct(vect) << '\n';
}
