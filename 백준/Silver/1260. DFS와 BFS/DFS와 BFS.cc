#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

bool isVisited[1001];
void dfs(int start, vector <vector<int>>& adj) {
    isVisited[start] = true;
    cout << start << " ";
    for (int i = 0; i < adj[start].size(); ++i) {
        int next = adj[start][i];
        if (!isVisited[next]) {
            dfs(next,adj);
        }
    }
}

void bfs(int start, vector<vector<int>>& adj) {
    queue<int> q;
    isVisited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < adj[node].size(); ++i) {
            int next = adj[node][i];
            if (!isVisited[next]) {
                isVisited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int N, M, V;

    cin >> N >> M >> V;

    vector <vector<int>> adj(N+1);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= N; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }
    dfs(V, adj);

    cout << endl;
    fill(isVisited, isVisited + N + 1, false);
    
    bfs(V, adj);


}
