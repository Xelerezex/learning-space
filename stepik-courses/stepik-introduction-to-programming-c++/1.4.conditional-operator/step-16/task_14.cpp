#include <iostream>
using namespace std;
int main() {
    // put your code here
    int A1,B1,C1,A2,B2,C2;
    cin >> A1 >> B1 >> C1 >> A2 >> B2 >> C2;
    // Проверим на равенство:
    if (((A1 == A2) && (B1 == B2) && (C1 == C2)) ||
        ((A1 == A2) && (C1 == B2) && (B1 == C2)) ||
        ((C1 == A2) && (B1 == B2) && (A1 == C2)) ||
        ((B1 == A2) && (A1 == B2) && (C1 == C2)) ||
        ((B1 == A2) && (C1 == B2) && (A1 == C2)) ||
        ((C1 == A2) && (A1 == B2) && (B1 == C2))
            ){
        cout << "Boxes are equal";
    }else if(((A1 <= A2) && (B1 <= B2) && (C1 <= C2)) ||
             ((A1 <= A2) && (C1 <= B2) && (B1 <= C2)) ||
             ((C1 <= A2) && (B1 <= B2) && (A1 <= C2)) ||
             ((B1 <= A2) && (A1 <= B2) && (C1 <= C2)) ||
             ((B1 <= A2) && (C1 <= B2) && (A1 <= C2)) ||
             ((C1 <= A2) && (A1 <= B2) && (B1 <= C2))
            ){
        cout << "The first box is smaller than the second one";
    }else if(((A1 >= A2) && (B1 >= B2) && (C1 >= C2)) ||
             ((A1 >= A2) && (C1 >= B2) && (B1 >= C2)) ||
             ((C1 >= A2) && (B1 >= B2) && (A1 >= C2)) ||
             ((B1 >= A2) && (A1 >= B2) && (C1 >= C2)) ||
             ((B1 >= A2) && (C1 >= B2) && (A1 >= C2)) ||
             ((C1 >= A2) && (A1 >= B2) && (B1 >= C2))
            ){
        cout << "The first box is larger than the second one";
    }else{
        cout << "Boxes are incomparable";
    }
    return 0;
}
