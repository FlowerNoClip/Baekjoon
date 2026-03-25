#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;
int N, M;
// . : 0 , # : 1 , J : 2, F : 3
vector<vector<int>> board, visited;
int ret = 1e9;
const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};
queue<pair<int, int>> fire;
void BurnFire()
{
    int qSize = fire.size();
    while(qSize--)
    {
        auto[y,x] = fire.front();
        fire.pop();

        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= 0 && ny < N && nx >= 0 && nx < M)
            {
                if(board[ny][nx] == 0 || board[ny][nx] == 2)
                {
                    board[ny][nx] = 3;
                    fire.push({ny , nx});
                }
            }
        }
    }
}
void bfs(int y, int x)
{
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 1;

    while(!q.empty())
    {
        BurnFire(); 
        int qSize = q.size();
        while(qSize--)
        {
            auto[y,x] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(ny < N && ny >= 0 && nx < M && nx >= 0)
                {
                    if(!visited[ny][nx] && board[ny][nx] == 0)
                    {
                        q.push({ny, nx});
                        visited[ny][nx] = visited[y][x] + 1;
                    }
                }
                else
                {
                    ret = visited[y][x];
                    return;
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
    int sy, sx;
    for(int i = 0; i < N; i++)
    {
        string temp; cin >> temp;
        for(int j = 0; j < M; j++)
        {
            if(temp[j] == '.')
            {
                board[i][j] = 0;
            }
            else if(temp[j] == '#')
            {
                board[i][j] = 1;
            }
            else if(temp[j] == 'J')
            {
                board[i][j] = 2;
                sy = i;
                sx = j;
            }
            else if(temp[j] == 'F')
            {
                board[i][j] = 3;
                fire.push({i,j});
            }
        }
    }

    bfs(sy, sx);
    if(ret == 1e9)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << ret << endl;
    }
}