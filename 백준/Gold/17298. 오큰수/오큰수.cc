#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
int n, a[1000004], ret[1000004];
stack<int> s;
int main()
{
    FAST_IO
    cin >> n;
    memset(ret, -1, sizeof(ret));
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        while(s.size() && a[s.top()] < a[i])
        {
            ret[s.top()] = a[i]; s.pop();
        }
        s.push(i);
    }

    for(int i = 0; i < n; i++) cout << ret[i] << " ";
}