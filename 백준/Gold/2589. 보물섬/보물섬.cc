#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;
vector<vector<int>> board;
vector<vector<int>> visited;
int N, M;
string temp;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
void bfs(int y, int x)
{
    vector<vector<int>> visiteds(N, vector<int>(M));
    queue<pair<int, int>> q;
    q.push({y, x});
    visiteds[y][x] = 1;
    while(!q.empty())
    {
        auto[y,x] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= 0 && ny < N && nx >= 0 && nx < M)
            {
                if(board[ny][nx] == 1 && !visiteds[ny][nx])
                {
                    visiteds[ny][nx] = visiteds[y][x] + 1;
                    q.push({ny, nx});
                    if(visited[ny][nx] < visiteds[ny][nx])
                    {
                        visited[ny][nx] = visiteds[ny][nx];
                    }
                }
            }
        }
    }
}
int main()
{
    FAST_IO
    cin >> N >> M;
    board.assign(N, vector<int>(M));
    visited.assign(N, vector<int>(M));
    for(int i = 0; i < N; i++)
    {
        cin >> temp;
        for(int j = 0; j < temp.length(); j++)
        {
            if(temp[j] =='L')
            {
                board[i][j] = 1;
            }
            else if(temp[j] =='W')
            {
                board[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(board[i][j] == 1)
            {
                bfs(i, j);
            }
        }
    }
    int maxNum = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            maxNum = max(maxNum, visited[i][j]);
        }
    }
    cout << maxNum -1;
}