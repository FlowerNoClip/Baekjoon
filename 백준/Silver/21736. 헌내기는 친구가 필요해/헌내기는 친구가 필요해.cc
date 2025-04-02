#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { -1, 1, 0, 0 };

// BFS 탐색 함수
void bfs(int startX, int startY, vector<vector<char>>& map, int&answer) {
    int N = map.size();
    int M = map[0].size();

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int, int>> q;

    q.push({ startX, startY });
    visited[startX][startY] = true;

    while (!q.empty()) {
        pair<int, int> maps = q.front();
        int x = maps.first;
        int y = maps.second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    if (map[nx][ny] == 'P') answer++;
                    if (map[nx][ny] == 'O' || map[nx][ny] == 'P') {
                        q.push({ nx, ny });
                    }
                }
            }

        }
    }


}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<char>> map(N, vector<char>(M));
    int answer = 0;

    int startX, startY;
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < temp.length(); j++)
        {
            map[i][j] = temp[j];

            if (map[i][j] == 'I') {
                startX = i;
                startY = j;
            }
        }

    }

    bfs(startX, startY, map, answer);
    if (answer)
    {
        cout << answer << endl;
    }
    else
    {
        cout << "TT" << endl;
    }
    

    return 0;
}