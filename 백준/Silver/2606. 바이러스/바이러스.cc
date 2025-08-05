#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int cnt = 0;
int M;
int N;

void dfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[start] = true;
    cnt++;
    for (int i = 0; i < adj[start].size(); i++) {
        int next = adj[start][i];
        if (!visited[next]) {
            dfs(next,adj,visited);
        }
    } 
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> M >> N;
    vector<vector<int>> adj(M+1);
    vector<bool> visited(M+1,false);
    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); 
        adj[v].push_back(u);
    }
    dfs(1, adj, visited);
    cout << cnt -1 << "\n";
}
