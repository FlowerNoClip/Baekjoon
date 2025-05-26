#include <vector>
#include <queue>
using namespace std;

int bfs(int x, int y, vector<vector<int>>& adj, vector<vector<bool>>& isVisited, int& n, int& m) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    isVisited[x][y] = true;

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };
    int distance = 1;  // 시작 위치도 거리 1로 포함

    while (!q.empty())
    {
        int qSize = q.size();  // 고정된 레벨 크기
        for (int i = 0; i < qSize; i++)
        {
            auto p = q.front();
            q.pop();

            int currentX = p.first;
            int currentY = p.second;

            if (currentX == n - 1 && currentY == m - 1) {
                return distance;
            }

            for (int j = 0; j < 4; ++j) {
                int nx = currentX + dx[j];
                int ny = currentY + dy[j];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !isVisited[nx][ny] && adj[nx][ny] == 1) {
                    q.push({ nx, ny });
                    isVisited[nx][ny] = true;
                }
            }
        }
        distance++;
    }
    return -1;  // 도달 못함
}

int solution(vector<vector<int>> maps)
{
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<bool>> isVisited(n, vector<bool>(m, false));
    return bfs(0, 0, maps, isVisited, n, m);
}
