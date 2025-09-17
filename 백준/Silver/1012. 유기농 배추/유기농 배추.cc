#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
using namespace std;
const int max_n = 54;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int visited[max_n][max_n] = {0};
void bfs(int x, int y, vector<vector<int>>& board)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;
    while(q.size())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            //if(nx > 0 || nx >= board[0].size() || ny < 0 || ny >= board.size() || board[nx][ny] == 0) continue;
            if(nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || board[nx][ny] == 0) continue;

            if(visited[nx][ny]) continue;

            q.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }

}
int main()
{
    int T; cin >> T;
    while(T--)
    {
        int cnt = 0;
        memset(visited, 0, sizeof(visited));
        int N, M, S; cin >> N >> M >> S;
        vector<vector<int>> arr(N, vector<int>(M));

        for(int i = 0; i < S; i++)
        {
            int a, b; cin >> a >> b;
            arr[a][b] = 1;
        }
        for(int i = 0; i < arr.size(); i++)
        {
            for(int j = 0; j < arr[0].size(); j++)
            {
                if(!visited[i][j] && arr[i][j] == 1)
                {
                    bfs(i,j,arr);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }
}