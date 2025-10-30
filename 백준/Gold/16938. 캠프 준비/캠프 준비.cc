#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n,l,r,x;
int ret, temp;
int main()
{
    FAST_IO

    cin >> n >> l >> r >> x;
    vector<int> a(n);

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    for (int mask = 0; mask < (1 << n); mask++) {

        int cnt = __builtin_popcount(mask); 
        if (cnt < 2) continue; // 2개 미만이면 패스
        vector<int> v;
        for (int j = 0; j < n; j++) {
            
            if (mask & (1 << j))
            {
                v.push_back(a[j]);
            } 
        }
        int num = 0;
        for(int i = 0; i < v.size(); i++)
        {
            num += v[i];
        }
        if(num <= r && num >= l && ((v[v.size()-1] - v[0]) >= x)) {ret ++;}
    }

     cout << ret << '\n';

    return 0;
}