#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 200000;
int n, m;
long long cnt[MAX+4];
int visited[MAX+4];

int main()
{
    cin >> n >> m;
    visited[n] = 1;
    cnt[n] = 1;
    queue<int> q;
    q.push(n);
    while(q.size())
    {
        int now = q.front(); q.pop();
        for(int next : {now + 1, now -1, now * 2})
        {
            if(next <= MAX && next  >= 0)
            {
                if(!visited[next])
                {
                    q.push(next);
                    visited[next] = visited[now] + 1;
                    cnt[next] += cnt[now];
                }
                else if(visited[next] == visited[now] + 1)
                {
                    cnt[next] += cnt[now];
                }
            }
        }
    }

    cout << visited[m]-1 << '\n';
    cout << cnt[m];
}