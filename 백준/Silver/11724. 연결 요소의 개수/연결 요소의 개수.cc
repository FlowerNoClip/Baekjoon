#include <iostream>
#include <vector>

using namespace std;


bool visited[1001] = { 0 };
void dfs(int start, vector<vector<int>>& adj) {
    visited[start] = true;
    for (int next:adj[start]) {
        if (!visited[next]) 
        {
            dfs(next, adj);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, V;


    cin >> N >> V;
    vector<vector<int>> adj(N+1);

    for (int i = 0; i < V; i++) {
        int u, v;
        cin >> u >> v;
        if(u <= N && v<=N)
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int components = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i,adj);
            components++;
        }
    }
    cout << components << endl;

    return 0;
}
