#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int cnt = 0;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int N, M;
int check[101][101]; 


void bfs(int x, int y, vector<vector<int>>& adj, vector<vector<bool>>& visited) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= adj.size() || ny < 0 || ny >= adj[0].size()) {
                continue;
            }
            if (adj[nx][ny] && !visited[nx][ny]) {
                check[nx][ny] = check[x][y] + 1;
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    vector<vector<int>> adj(N, vector<int>(M));
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++) {
            adj[i][j] = str[j] - '0';
        }
    }


    bfs(0, 0, adj, visited);
    
    cout << check[N - 1][M - 1] + 1;

    
}
