#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    FAST_IO
    int tc, n; cin >> tc;
    
    for(int t = 1; t <= tc; t++)
    {
        cin >> n;
        vector<vector<long long>> pas(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) 
        {
        pas[i][0] = 1; 
        pas[i][i] = 1; 

            for (int j = 1; j < i; j++) 
            {
                pas[i][j] = pas[i-1][j-1] + pas[i-1][j];
                // i : 2 || j : 1
            }
        
        }
        cout << "#" << t << "\n";
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j <= i; j++) 
            {
                cout << pas[i][j];
                if (j != i) cout << " ";
            }
            cout << "\n";
        }
    }
     
}