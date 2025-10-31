#include <bits/stdc++.h>
using namespace std;
#define FSAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int t, n, m, a, b, visited[1004], cnt;
vector<int> adj[1004];
void dfs(int here)
{
    visited[here] = 1;
    for(int a : adj[here])
    {
        if(!visited[a]) dfs(a);
    }
    return;
}

int main()
{
    cin >> t;
    while(t--)
    {
        for(int i = 0; i < 1004; i++)adj[i].clear();
        fill(visited, visited+1004, 0);

        cnt = 0;
        cin >> n >> m;
        for(int i = 0; i < m; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i = 1; i <= n; i++)
        {
            if(!visited[i])
            {
                dfs(i);
                cnt++;
            }
        }

        if(m == n-1 && cnt == 1)
        {
            cout << "tree" << endl;
        } 
        else
        {
            cout << "graph" << endl;
        }
    }


}