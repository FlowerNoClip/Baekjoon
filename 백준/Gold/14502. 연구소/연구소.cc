#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <queue> 
using namespace std;

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int N, M; 
int dx[] = { 0, 0, 1 , -1 };
int dy[] = { 1, -1, 0, 0 };
int cnt = 0;

void spreadVirus(vector<vector<int>>& tempBoard) {
    queue<pair<int, int>> q;

    // 모든 바이러스 위치에서 BFS 시작
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tempBoard[i][j] == 2) {
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (tempBoard[nx][ny] == 0) {
                    tempBoard[nx][ny] = 2; // 감염
                    q.push({nx, ny});
                }
            }
        }
    }
}

int getSafeArea(vector<vector<int>>& tempBoard) {
    int safe = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tempBoard[i][j] == 0) safe++;
        }
    }
    return safe;
}

void makeWall(int wallcnt, vector<vector<int>>& board) {
    if (wallcnt == 3) {
        vector<vector<int>> tempBoard = board; // 원본 복사
        spreadVirus(tempBoard); // 바이러스 확산
        cnt = max(cnt, getSafeArea(tempBoard)); // 안전구역 최대값 갱신
        return;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0) {
                board[i][j] = 1; // 벽 설치
                makeWall(wallcnt + 1, board);
                board[i][j] = 0; // 원상 복구
            }
        }
    }
}

int main() {
    FAST_IO;
    cin >> N >> M;
    vector<vector<int>> board(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    makeWall(0, board);
    cout << cnt;
}
