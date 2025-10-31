#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
int n, m, ret, a[4][4];
int main()
{
    FAST_IO
    cin >> n >> m;
    for(int i = 0; i < n ; i++)
    {
        string s; cin >> s;
        for(int j = 0; j < m; j++)
        {
            a[i][j] = s[j] - '0';
        }
    }

    for(int s = 0; s < (1 << (n * m)); s++)
    {
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            int cur = 0;
            for(int j = 0; j < m; j++)
            {
                int k = i * m + j;
                if((s & (1 << k)) == 0)
                {
                    cur = cur * 10 + a[i][j];
                }
                else
                {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        for(int i = 0; i < m; i++)
        {
            int cur = 0;
            for(int j = 0; j < n; j++)
            {
                int k = j * m + i;
                if((s & (1 << k)) != 0)
                {
                    cur = cur * 10 + a[j][i];
                }
                else
                {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        ret = max(ret, sum);
    }
    cout << ret;
}