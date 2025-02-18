#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int cnt = 0;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int N, M;
bool visited[100] = { 0 };
int x, y;

int bfs(int start, vector<vector<int>>& adj) {
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;
    
    while (!q.empty()) {
        int node = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (node == y) {
            return cnt;
            break;
        }
        for (int i = 0; i < adj[node].size(); i++) {
            int next = adj[node][i];

            if (!visited[next]) {
                visited[next] = true;
                q.push({ next, cnt + 1 });
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    cin >> x >> y;
    cin >> M;
    vector<vector<int>> adj(N+1);
    
    for (int i = 0; i < M; i++) {
        int r, v;
        cin >> r >> v;
        adj[r].push_back(v);
        adj[v].push_back(r);
    }

    int result = bfs(x,adj);

    cout << result << endl;
    
}
