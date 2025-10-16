#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, m;
int board[54][54];
int visited[54][54];
int distArr[54][54];

int dx[] = {0, 0, 1, -1};   
int dy[] = {1, -1, 0, 0};   

inline bool isValid(int y, int x) {
    return (0 <= y && y < n && 0 <= x && x < m && !visited[y][x] && board[y][x]);
}

int bfs(int sy, int sx) {
    queue<pair<int,int>> q;
    memset(visited, 0, sizeof(visited));
    memset(distArr, -1, sizeof(distArr));

    visited[sy][sx] = 1;
    distArr[sy][sx] = 0;
    q.push({sy, sx});

    int localMax = 0;

    while (!q.empty()) {
        auto [y, x] = q.front(); q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (!isValid(ny, nx)) continue;

            visited[ny][nx] = 1;
            distArr[ny][nx] = distArr[y][x] + 1;
            localMax = max(localMax, distArr[ny][nx]);
            q.push({ny, nx});
        }
    }
    return localMax;
}

int main() {
    FAST_IO

    cin >> n >> m;

    for (int i = 0; i < n; i++) 
    {
        string temp; cin >> temp;
        for (int j = 0; j < m; j++) 
        {
            if (temp[j] == 'L') board[i][j] = 1; 
            else if (temp[j] == 'W') board[i][j] = 0;
        }
    }

    int ret = 0; 
    for (int y = 0; y < n; y++) 
    {
        for (int x = 0; x < m; x++) 
        {
            if (board[y][x] == 1) {
                ret = max(ret, bfs(y, x));
            }
        }
    }

    cout << ret << '\n';
    return 0;
}
