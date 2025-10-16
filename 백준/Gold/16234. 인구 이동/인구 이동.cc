#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, l, r;
int board[54][54];
int visited[54][54];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

inline bool isValid(int y, int x) {
    return (0 <= y && y < n && 0 <= x && x < n && !visited[y][x]);
}


bool bfs(int sy, int sx) {
    queue<pair<int,int>> q;
    vector<pair<int,int>> united; 
    q.push({sy, sx});
    visited[sy][sx] = 1;
    united.push_back({sy, sx});
    int sum = board[sy][sx];

    while(!q.empty()) {
        auto [y, x] = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (!isValid(ny, nx)) continue;

            int diff = abs(board[y][x] - board[ny][nx]);
            if (l <= diff && diff <= r) {
                visited[ny][nx] = 1;
                q.push({ny, nx});
                united.push_back({ny, nx});
                sum += board[ny][nx];
            }
        }
    }

    if (united.size() <= 1) return false;

    int avg = sum / united.size();
    for (auto [y, x] : united) {
        board[y][x] = avg;
    }

    return true;
}

int main() {
    FAST_IO
    cin >> n >> l >> r;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    int answer = 0;

    while (true) {
        memset(visited, 0, sizeof(visited));
        bool moved = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (bfs(i, j)) moved = true;
                }
            }
        }

        if (!moved) break; // 이동이 없으면 종료
        answer++;
    }

    cout << answer << '\n';
    return 0;
}
