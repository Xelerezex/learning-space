#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


long long int MaximumPairwiseProduct(vector<int> &data) {
    sort(begin(data), end(data));
    return data[data.size() - 2] * data.front();
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
