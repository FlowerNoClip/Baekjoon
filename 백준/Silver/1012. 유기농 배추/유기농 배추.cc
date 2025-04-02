#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

void dfs(int x, int y, vector<vector<int>>& arr, vector<vector<bool>>& visited)
{
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) { 
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < arr.size() && ny >= 0 && ny < arr[0].size()) {
            if (!visited[nx][ny] && arr[nx][ny] == 1) {
                visited[nx][ny] = true;
                dfs(nx, ny, arr, visited);
            }
        }
    }

}
int main() {
    int dy[] = { 0, 0, -1, 1 };
    int dx[] = { 1, -1, 0, 0 };
    int T; cin >> T;
    int N, M;
    int A;

    
    while (T--)
    {
        cin >> M >> N >> A;
        vector<vector<int>> arr(M, vector<int>(N, 0));
        vector<vector<bool>> visited(M, vector<bool>(N, 0));
        for (int i = 0; i < A; i++)
        {
            int x, y;
            cin >> x >> y;
            arr[x][y] = 1;
        }
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr[0].size(); j++)
            {
                if (!visited[i][j] && arr[i][j] == 1)
                {
                    dfs(i, j, arr, visited);
                    cnt++;
                }
            }
        }

        cout << cnt << endl;
        
    }

    

    return 0;
}