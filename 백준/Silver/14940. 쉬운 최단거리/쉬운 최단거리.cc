#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { -1, 1, 0, 0 };

// BFS 탐색 함수
void bfs(int startX, int startY, vector<vector<int>>& map, vector<vector<int>>& answer) {
    int N = map.size();
    int M = map[0].size();

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int, int>> q;

    q.push({ startX, startY });
    visited[startX][startY] = true;
    answer[startX][startY] = 0; // 시작 위치는 0으로 설정

    while (!q.empty()) {
        pair<int, int> maps = q.front();
        int x = maps.first;
        int y = maps.second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny] && map[nx][ny] == 1) {
                visited[nx][ny] = true;
                answer[nx][ny] = answer[x][y] + 1; // 거리 갱신
                q.push({ nx, ny });
            }
        }
    }

    // 도달할 수 없는 곳은 -1 유지
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0)
            {
                answer[i][j] = 0;
            }
            if (map[i][j] == 1 && answer[i][j] == -1) {
                answer[i][j] = -1;
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> map(N, vector<int>(M));
    vector<vector<int>> answer(N, vector<int>(M, -1)); // 기본값 -1

    int startX, startY;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                startX = i;
                startY = j;
            }
        }
    }

    bfs(startX, startY, map, answer);

    // 결과 출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}