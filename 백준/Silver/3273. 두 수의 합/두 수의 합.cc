#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int a[100001], n, x;
int main()
{
    FAST_IO
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    cin >> x;
    sort(a, a+n);
    int l = 0, r = n-1;
    int ret = 0;
    while(l < r)
    {
        int sum = a[l] + a[r];
        if(sum == x) {
            ret++;
            l++;
            r--;
        }
        else if(sum > x) r--;
        else l++;
    }
    cout <<ret;
}