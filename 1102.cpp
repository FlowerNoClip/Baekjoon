#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int cnt = 0;
int M, N, V;
bool visited[50][50] = { 0 };

void dfs(int x, int y, vector<vector<int>>& S) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

        if (S[nx][ny] && !visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(nx, ny, S);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        cin >> M >> N >> V;
        vector<vector<int>> S(M, vector<int>(N, 0));
        cnt = 0;
        for (int i = 0; i < 50; i++) {
            fill(visited[i], visited[i] + 50, false);
        }

        for (int i = 0; i < V; i++) {
            int u, v;
            cin >> u >> v;
            S[u][v] = 1;
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (S[i][j] && !visited[i][j]) {
                    cnt++;
                    visited[i][j] = true;
                    dfs(i, j, S);
                }
            }
        }

        cout << cnt << '\n';
    }
    return 0;
}
