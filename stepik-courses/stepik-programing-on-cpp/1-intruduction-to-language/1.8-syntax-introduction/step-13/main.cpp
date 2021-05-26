#include <iostream>
using namespace std;

int log(const int& num){
    int s_num = 0;
    int val = 2;

    while(val <= num) {
        val *= 2;
        ++s_num;
    }

    return s_num;
}

int main(){
    int qua;
    cin >> qua;
    for(int i = 0; i < qua; ++i){
        int num_for_it;
        cin >> num_for_it;
        cout << log(num_for_it) << endl;
    }
    return 0;
}
