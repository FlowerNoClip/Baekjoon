#include <bits/stdc++.h>
using namespace std;
#define prev aaa
#define next aaaa 
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 200000;
int n, k, ret, visited[MAX+4], prev[MAX+4], here;
queue<int> q;
vector<int> v;

int main()
{
    FAST_IO
    cin >> n >> k;
    visited[n] = 1;
    q.push(n);
    while(q.size())
    {
        here = q.front(); q.pop();
        if(here == k )
        {
            ret = visited[k];
            break;
        }
        for(int next : {here + 1, here - 1, here * 2})
        {
            if(next >= 0 && next <= MAX && !visited[next])
            {
                q.push(next);
                visited[next] = visited[here] + 1;
                prev[next] = here;
            }
        }
    }

    for(int i = k; i != n; i = prev[i])
    {
        v.push_back(i);
    }
    v.push_back(n);
    cout << ret-1 << '\n';
    reverse(v.begin(), v.end());
    for(int i : v) cout << i << " ";
}