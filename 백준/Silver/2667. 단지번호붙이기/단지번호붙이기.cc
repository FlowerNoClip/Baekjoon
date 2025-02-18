#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int cnt = 0;
vector<int> v;
bool visited[101][101] = {false};
int N;

void dfs(int x, int y, vector<vector<int>>& adj) {
    visited[x][y] = true;
    cnt++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {  // 0-based 범위 체크
            if (adj[nx][ny] && !visited[nx][ny]) {
                dfs(nx, ny, adj);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    vector<vector<int>> adj(N, vector<int>(N));  // N x N 배열

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++) {
            adj[i][j] = row[j] - '0';  // 0-based 배열에 값 입력
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (adj[i][j] && !visited[i][j]) {
                cnt = 0;
                dfs(i, j, adj);
                if (cnt > 0) {  // 크기가 1인 단지도 포함
                    v.push_back(cnt);
                }
            }
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }

    return 0;
}
