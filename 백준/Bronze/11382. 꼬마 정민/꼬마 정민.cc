#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    long long Arr[3];

    for(int i = 0 ; i < 3; i ++)
        {
            cin >> Arr[i];
        }

    cout << Arr[0] + Arr[1] + Arr[2] << endl;
    
    return 0;
}