#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    while(true)
        {
            
            vector<int> Arr(3);
            cin >> Arr[0] >> Arr[1] >> Arr[2];
            if((!Arr[0] && !Arr[1]) && !Arr[2])
            {
                break;
            }
            sort(Arr.begin(), Arr.end());
            if(Arr[2]*Arr[2] == ((Arr[1]*Arr[1]) + (Arr[0]*Arr[0])))
            {
                cout << "right" << endl;
            }
            else
            {
                cout << "wrong" << endl;
            }

            
        }
    return 0;
}