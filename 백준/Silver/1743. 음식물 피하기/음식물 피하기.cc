#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = { 0, 0 , 1, -1 };
int N, M, K;
bool visited[101][101] = { 0 };
int cnt = 0;
vector<int> v;
void dfs(int y, int x, vector<vector<int>>& adj) {
    visited[y][x] = true;
    cnt++;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 1 && ny <= N && nx >= 1 && nx <= M) {  // 범위 확인
            if (adj[ny][nx] && !visited[ny][nx]) {
                dfs(ny, nx, adj);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> N >> M >> K;
    vector<vector<int>> adj(N+1, vector<int>(M+1));

    for (int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        adj[r][c] = 1;
    }
    
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++) {
            if (adj[i][j] && !visited[i][j]) {
                cnt = 0;
                dfs(i, j, adj);
                v.push_back(cnt);
                
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v[v.size()-1] << endl;

}
