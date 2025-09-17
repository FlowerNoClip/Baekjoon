#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool check(int nx, int ny, vector<vector<int>>& board, vector<vector<bool>>& visited)
{
    int M = board.size();
    int N = board[0].size();
    if (nx < 0 || nx >= M || ny < 0 || ny >= N) return false; 
    if (board[nx][ny] == 1) return false; 
    if (visited[nx][ny]) return false; 
    return true;
}

int bfs(int sX, int sY, vector<vector<int>>& board, vector<vector<bool>>& visited)
{
    queue<pair<int,int>> q;
    q.push({sX, sY});
    visited[sX][sY] = true;
    int cnt = 1; 

    while(!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!check(nx, ny, board, visited)) continue;

            q.push({nx, ny});
            visited[nx][ny] = true;
            cnt++;
        }
    }

    return cnt;
}

int main()
{
    FAST_IO
    int M, N, K; 
    cin >> M >> N >> K; 
    vector<vector<int>> board(M, vector<int>(N, 0));
    vector<vector<bool>> visited(M, vector<bool>(N, false));

    for(int i = 0; i < K; i++)
    {
        int x1, y1, x2, y2; 
        cin >> x1 >> y1 >> x2 >> y2;
        for(int y = y1; y < y2; y++)
        {
            for(int x = x1; x < x2; x++)
            {
                board[y][x] = 1;
            }
        }
    }

    vector<int> answer;


    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(board[i][j] == 0 && !visited[i][j])
            {
                answer.push_back(bfs(i, j, board, visited));
            }
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << '\n';
    for(int a : answer) cout << a << ' ';
}
