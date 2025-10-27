#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int dy[] = {0, 0, 1, -1, 0};
const int dx[] = {1, -1, 0, 0, 0};

int n;
int board[12][12];
int visited[12][12];
int ret = 987654321;
int check()
{
    int num = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(visited[i][j])
            {
                num += board[i][j];
            }
        }
    }

    return num;
}
void go(int sx, int sy, int cnt)
{
    if(cnt == 3)
    {
        ret = min(ret, check());
        return;
    }
    for(int i = 1; i <= n-2; i++)
    {
        for(int j = 1; j <= n-2; j++)
        {
            if( visited[i][j] || visited[i-1][j] ||visited[i+1][j] || visited[i][j+1] || visited[i][j-1]) continue;
            
            for(int dir = 0; dir < 5; dir++)
            {
                int nx = j + dx[dir];
                int ny = i + dy[dir];
                visited[ny][nx] = 1;
            }
            go(i, j, cnt+1);
            for(int dir = 0; dir < 5; dir++)
            {
                int nx = j + dx[dir];
                int ny = i + dy[dir];
                visited[ny][nx] = 0;
            }
        }
    }
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    go(0,0,0);

    cout << ret;
}