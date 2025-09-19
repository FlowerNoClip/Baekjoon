#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

int N, M;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int answer = 0;
vector<vector<int>> arr;

void virus(vector<vector<int>>& tempBoard)
{
    queue<pair<int,int>> q;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(tempBoard[i][j] == 2)
                q.push({i,j});
        }
    }

    while(!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M)
            {
                if(tempBoard[nx][ny] == 0)
                {
                    tempBoard[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int safeArea(const vector<vector<int>>& board)
{
    int cnt = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(board[i][j] == 0)
                cnt++;
        }
    }
    return cnt;
}

void makeWall(int wallCount)
{
    if(wallCount == 3)
    {
        vector<vector<int>> board = arr;
        virus(board);
        answer = max(answer, safeArea(board));
        return;
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(arr[i][j] == 0)
            {
                arr[i][j] = 1;
                makeWall(wallCount + 1);
                arr[i][j] = 0;
            }
        }
    }
}

int main()
{
    FAST_IO
    cin >> N >> M;
    arr.assign(N, vector<int>(M, 0));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
            cin >> arr[i][j];
    }

    makeWall(0);
    cout << answer << "\n";
    return 0;
}
