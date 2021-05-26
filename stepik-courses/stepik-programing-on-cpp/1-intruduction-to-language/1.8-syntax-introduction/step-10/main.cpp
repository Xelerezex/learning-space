#include <iostream>
using namespace std;

int main()
{
    int count;
    cin >> count;
    for(int i = 0; i < count; ++i){
        int x, y;
        cin >> x >> y;
        cout << x + y << endl;
    }

    return 0;
}
