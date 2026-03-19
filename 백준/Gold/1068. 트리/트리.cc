#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define endl '\n'
vector<int> adj[55];
int root, d;
int dfs(int here)
{
    int ret = 0;
    int node = 0;
    for(int there : adj[here])
    {
        if(there == d) continue;
        ret += dfs(there);
        node++;
    }
    if(node == 0) return 1;
    return ret;
}
int main()
{
    FAST_IO
    int N; cin >> N;
    int v;
    for(int i = 0; i < N; i++)
    {
        cin >> v;
        if(v == -1)
        {
            root = i;
        }
        else
        {
            adj[v].push_back(i);
        }
        
    }

    cin >> d;
    if(d == root)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << dfs(root) << endl;
}