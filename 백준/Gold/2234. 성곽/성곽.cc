#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int n, m, cnt, mx, big, a[51][51], visited[51][51], comp[2600];
int dfs(int y, int x, int cnt)
{
    if(visited[y][x]) return 0;
    visited[y][x] = cnt;
    int ret = 1;
    for(int i = 0; i <4 ; i++)
    {
        if(!(a[y][x] & (1 << i)))
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            ret += dfs(ny, nx, cnt);
        }
    }
    return ret;
}
int main()
{
    FAST_IO
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!visited[i][j])
            {
                cnt++;
                comp[cnt] = dfs(i,j,cnt);
                mx = max(mx, comp[cnt]);
            }
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i+1 < m)
            {
                int a = visited[i+1][j];
                int b = visited[i][j];
                if(a != b)
                {
                    big = max(big, comp[a] + comp[b]);
                }
            }
            if(j+1 < n)
            {
                int a = visited[i][j+1];
                int b = visited[i][j];
                if(a != b)
                {
                    big = max(big, comp[a] + comp[b]);
                }
            }
        }
    }

    cout << cnt << '\n' << mx << '\n' << big;
}