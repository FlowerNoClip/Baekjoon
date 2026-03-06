#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0 ,0, 1, -1};
int main()
{
    FAST_IO
    int N, M; cin >> N >> M;
    vector<vector<int>> board(N, vector<int>(M));
    vector<vector<int>> dist(N, vector<int>(M));

    for(int i = 0; i < N; i++)
    {
        string temp; cin >> temp;
        for(int j = 0; j < M; j++)
        {
            board[i][j] = temp[j] - '0';
        }
    }

    queue<pair<int, int>> q;
    q.push({0,0});
    dist[0][0] = 1;
    while(!q.empty())
    {
        auto [y,x] = q.front();
        q.pop();
        if(y == N-1 && x == M - 1)
        {
            cout << dist[y][x] << '\n';
            return 0;
        }
        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= 0 && ny < N && nx >= 0 && nx < M && !dist[ny][nx] && board[ny][nx] == 1)
            {
                q.push({ny, nx});
                dist[ny][nx] = dist[y][x] + 1;
            }
        }
        
    }
}
