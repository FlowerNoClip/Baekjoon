#include <iostream>
#include <queue>
#include <vector>
using namespace std;



int main() {
    int dy[] = { 0, 0, -1, 1 };
    int dx[] = { 1, -1, 0, 0 };
    int N, M;

    cin >> M >> N;
    vector<vector<int>> arr(N, vector<int>(M));
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                q.push({ i, j }); // 모든 익은 토마토를 큐에 넣어야 함
                visited[i][j] = true;
            }
        }
    }
    
    int depth = -1; 
    while (!q.empty()) {
        int size = q.size(); 
        depth++; 
        for (int s = 0; s < size; s++) {
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                    if (!visited[nx][ny] && arr[nx][ny] == 0) { // 익지 않은 토마토만 탐색
                        visited[nx][ny] = true;
                        arr[nx][ny] = 1; // 토마토를 익게 만듦
                        q.push({ nx, ny });
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0) { // 아직 익지 않은 토마토가 있다면
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << depth << endl; // 모든 토마토가 익는 데 걸린 시간 출력
    return 0;
}