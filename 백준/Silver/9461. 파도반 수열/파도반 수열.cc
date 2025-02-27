#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    long long DP[101];
    DP[0] = 1;
    DP[1] = 1;
    DP[2] = 1;
    DP[3] = 2;
    DP[4] = 2;
    
    for(int i = 5; i < 101; i++)
        {
            DP[i] = DP[i-1] + DP[i-5];
        }
    while(T--)
        {
            int N;
            cin >> N;

            cout << DP[N-1] << endl;
        }
    
    return 0;
}