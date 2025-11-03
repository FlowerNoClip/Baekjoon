#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int n;
int main()
{
    FAST_IO
    cin >> n;
    vector<int> a(n);
    for(int& i : a) cin >> i;
    int maxNum = 0;
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++)
    {
        maxNum = max(maxNum, a[i] * (n - i));
    }
    cout << maxNum;
}