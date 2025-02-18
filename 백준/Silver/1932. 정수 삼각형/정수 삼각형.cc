#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int DP[1001][1001];
    int N;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<=i; j++)
        {
            cin >> DP[i][j];
        }        
    }

    for(int i=N-1; i>=1; i--)
    {
        for(int j=0; j<=i; j++)
        {
            DP[i-1][j] += max(DP[i][j],DP[i][j+1]);
        }        
    }

    cout << DP[0][0] << endl;

    


    
    return 0;
}