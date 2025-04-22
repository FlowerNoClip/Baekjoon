#include <iostream>
using namespace std;

int N, M, answer;                  // N: 세로, M: 가로, answer: 최대 점수
int board[555][555];              // 테트로미노가 놓일 보드
int visited[555][555];            // DFS 방문 체크

int dy[4] = {1, 0, -1, 0};         // 상하좌우 이동
int dx[4] = {0, 1, 0, -1};

// DFS를 통해 4칸짜리 도형을 탐색 (보라색 'ㅗ' 제외)
void dfs(int y, int x, int count, int sumVal) {
    if (count == 4) {
        answer = max(answer, sumVal);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 1 || ny > N || nx < 1 || nx > M) continue;
        if (visited[ny][nx]) continue;

        visited[ny][nx]++;
        dfs(ny, nx, count + 1, sumVal + board[ny][nx]);
        visited[ny][nx]--;
    }
}

// 보라색 'ㅗ' 모양 4가지 하드코딩 처리
int tShape[4][4][2] = {
    { {0,0}, {0,-1}, {0,1}, {1,0} },   // ㅗ
    { {0,0}, {0,-1}, {0,1}, {-1,0} },  // ㅜ
    { {0,0}, {-1,0}, {1,0}, {0,-1} },  // ㅓ
    { {0,0}, {-1,0}, {1,0}, {0,1} }    // ㅏ
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cin >> board[i][j];

    // DFS로 모든 도형 탐색 (ㅗ 제외)
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            visited[i][j]++;
            dfs(i, j, 1, board[i][j]);
            visited[i][j]--;
        }
    }

    // 'ㅗ' 모양 하드코딩 처리
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            for (int t = 0; t < 4; ++t) {
                int sum = 0;
                bool isValid = true;

                for (int b = 0; b < 4; ++b) {
                    int ny = i + tShape[t][b][0];
                    int nx = j + tShape[t][b][1];

                    if (ny < 1 || ny > N || nx < 1 || nx > M) {
                        isValid = false;
                        break;
                    }
                    sum += board[ny][nx];
                }

                if (isValid)
                    answer = max(answer, sum);
            }
        }
    }

    cout << answer;
    return 0;
}
