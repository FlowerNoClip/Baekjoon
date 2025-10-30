#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int n, x, y;
long long ret = 1e9;
int main()
{
    cin >> n;
    vector<pair<int, int>> a(n);

    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        a[i] = {x, y};  
    }


    for (int mask = 1; mask < (1 << n); mask++) 
    {
        long long sour = 1;
        long long salt = 0;
        for(int j = 0; j < n; j++)
        {
            if(mask & (1<<j))
            {
                sour *= a[j].first;
                salt += a[j].second;
            }
        }
        ret = min(ret, abs(sour - salt));
    }

    cout << ret;


}
