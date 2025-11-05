#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int n;

int main() {
    FAST_IO;
    int n;
    cin >> n;
    vector<vector<int>> s(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> s[i][j];
        }            
    }
    int ans = 1e9;
    for (int mask = 0; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) != n / 2) continue;

        vector<int> start, link;
        for(int i = 0; i < n; i++)
        {
            if(mask & (1 << i))
            {
                start.push_back(i);
            }
            else
            {
                link.push_back(i);
            }
        }

        int startSum = 0, linkSum = 0;
        for (int i = 0; i < n / 2; i++) 
        {
            for (int j = i + 1; j < n / 2; j++) 
            {
                startSum += s[start[i]][start[j]] + s[start[j]][start[i]];
                linkSum += s[link[i]][link[j]] + s[link[j]][link[i]];
            }
        }

        ans = min(ans, abs(startSum - linkSum));
        
    }

    cout << ans ;
}