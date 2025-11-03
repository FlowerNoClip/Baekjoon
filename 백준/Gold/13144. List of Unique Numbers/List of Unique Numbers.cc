#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

long long s, e, cnt[1000001], n, a[100001];
long long ret;

int main()
{
    FAST_IO
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    while(e < n)
    {
        if(!cnt[a[e]])
        {
            cnt[a[e]]++;
            e++;
        }
        else
        {
            ret += (e - s);
            cnt[a[s]] --;
            s++;
        }
    }

    ret += (long long) (e-s) * (e - s + 1) / 2;
    cout << ret;
}