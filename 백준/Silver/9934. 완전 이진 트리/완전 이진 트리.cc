#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, a[1040];
vector<int> ret[14];
void go(int s, int e, int level)
{
    if(s > e) return;
    if(s == e)
    {
        ret[level].push_back(a[s]);
        return;
    }
    int mid = (s+e) /2;
    ret[level].push_back(a[mid]);
    go(s, mid-1, level+1);
    go(mid+1, e, level+1);
    return;
}
int main()
{
    FAST_IO
    cin >> n;
    int end = (int)pow(2, n) - 1;
    for(int i = 0; i < end; i++) cin >> a[i];
    go(0, end, 1);
    for(int i = 1; i <= n; i++)
    {
        for(int j : ret[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}