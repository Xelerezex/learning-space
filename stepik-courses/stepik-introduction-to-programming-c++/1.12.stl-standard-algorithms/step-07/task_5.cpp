#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Student {
    string name, surname;
    int math, phys, comp_science;
};

bool cmp(Student a, Student b) {
    return a.math + a.phys + a.comp_science > b.math + b.phys + b.comp_science;
}

int main(void) {
    int n;
    cin >> n;
    if (n < 1) return 1;

    vector<Student> data(n);
    for (int i = 0; i < n; ++i) {
        cin >> data[i].name >> data[i].surname;
        cin >> data[i].math >> data[i].phys >> data[i].comp_science;
    }
    stable_sort(data.begin(), data.end(), cmp);

    for (auto s : data)
        cout << s.name << " " << s.surname << endl;
    return 0;
}
