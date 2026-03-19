#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
using namespace std;
#define endl '\n'
int a, b, mx;
vector<int> adj[10001];
bool visited[10001];
int dp[10001];
int dfs(int here)
{
    visited[here] = true;
    int ret = 1;
    for(int next : adj[here])
    {
        if(!visited[next])
        {
            ret+=dfs(next);
        }        
    }
    return ret;
}
int main()
{
    FAST_IO
    int N, M; cin >> N >> M;
    while(M--)
    {
        cin >> a >> b;
        adj[b].push_back(a);
    }
    for(int i = 1; i <= N; i++)
    {
        memset(visited, false, sizeof(visited));
        dp[i] = dfs(i);
        mx = max(dp[i], mx);
    }

    for(int i = 1; i <= N; i++)
    {
        if(dp[i] == mx)
        {
            cout << i << ' ';
        }
    }
    
}