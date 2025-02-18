#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0 , 1, -1 };
int cnt = 0;
vector<int> v;

int M, N, K;
void dfs(int x, int y, vector<vector<int>>& map, vector<vector<bool>>& visited) {
    visited[x][y] = true;
    cnt++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if (!map[nx][ny] && !visited[nx][ny]) {
                dfs(nx, ny, map, visited);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> M >> N >> K;
    vector<vector<int>> map(N, vector<int>(M, 0));
    vector<vector<bool>> visited(N, vector<bool>(M, 0));
    //vector<vector<int>> adj;
    for (int i = 0; i < K; i++) {
        int x, y, xx, yy;
        cin >> x >> y >> xx >> yy;
        for (int j = x; j < xx; j++) {
            for (int k = y; k < yy; k++) {
                map[j][k] = 1;
            }
        }
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!map[i][j] && !visited[i][j]) {
                cnt = 0;
                dfs(i, j, map, visited);
                v.push_back(cnt);
            }
        }
    }

    sort(v.begin(), v.end());

    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

}
