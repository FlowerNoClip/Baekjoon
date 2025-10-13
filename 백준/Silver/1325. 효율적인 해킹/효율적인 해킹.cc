#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int n, m;
int a, b;
vector<int> v[10004];
int visited[10004];
int dp[10004];
int mx;
int dfs(int here)
{
    visited[here] = 1;
    int ret = 1;
    for(int there : v[here])
    {
        if(visited[there]) continue;
        ret += dfs(there);
    }
    return ret;
}

int main()
{
    FAST_IO
    cin >> n >> m;
    while(m--)
    {
        cin >> a >> b;
        v[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
    {
        memset(visited, 0, sizeof(visited));
        dp[i] = dfs(i);
        mx = max(dp[i], mx);
    }
    for(int i = 1; i <= n; i++) if(mx == dp[i]) cout << i << " ";
}
