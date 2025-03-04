#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int Num; cin >> Num;
    vector<int> Arr(6);
    for(int i = 0 ; i < Arr.size(); i++)
        {
            cin >> Arr[i];
        }
    int T, P;
    cin >> T >> P;

    int Cloths = 0;


    for(int i = 0 ; i < Arr.size(); i++)
        {
            Cloths += (Arr[i] + T - 1) / T; 
        }


    cout << Cloths << endl << Num/P << " " << Num % P << endl;
    return 0;
}