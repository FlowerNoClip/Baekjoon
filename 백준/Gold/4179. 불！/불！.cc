#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int r, c, board[1004][1004], firetiming[1004][1004], visited[1004][1004]; 
pair<int, int> start, fireStart;
int dx[] = { 0, 0, 1, -1};
int dy[] = { 1, -1, 0, 0};

inline bool inRange(int y, int x) {
    return (0 <= y && y < r && 0 <= x && x < c);
}
inline bool onEdge(int y, int x) {
    return (y == 0 || y == r-1 || x == 0 || x == c-1);
}

inline bool isPlayerValid(int y, int x)
{
    return inRange(y,x) && visited[y][x] == 0 && board[y][x] != 1;
}

inline bool isFireValid(int y, int x)
{
    return inRange(y,x) && firetiming[y][x] == 0 && board[y][x] != 1;
}

void firebfs()
{
    queue<pair<int, int>> q;

    for (int i = 0; i < r; i++) 
    {
        for (int j = 0; j < c; j++) 
        {
            if (board[i][j] == 3) 
            {
                q.push({i, j});
                firetiming[i][j] = 1; 
            }
        }        
    }
        
    while(!q.empty())
    {
        auto [y,x] = q.front(); q.pop();
        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(isFireValid(ny, nx))
            {
                firetiming[ny][nx] = firetiming[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
}

int bfs(int sy, int sx)
{
    queue<pair<int,int>> q;
    q.push({sy, sx});
    visited[sy][sx] = 1;

    if (onEdge(sy, sx)) return visited[sy][sx];

    while(!q.empty())
    {
        auto [y,x] = q.front(); q.pop();

        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (!inRange(ny,nx)) continue;

            if (isPlayerValid(ny, nx))
            {
                if (firetiming[ny][nx] == 0 || visited[y][x] + 1 < firetiming[ny][nx])
                {
                    visited[ny][nx] = visited[y][x] + 1;
                    if (onEdge(ny, nx)) return visited[ny][nx];

                    q.push({ny, nx});
                }
            }
        }
    }
    return -1;
}

int main()
{
    FAST_IO;
    cin >> r >> c;

    for(int i = 0; i < r; i++)
    {
        string temp; cin >> temp;
        for(int j = 0; j < c; j++)
        {
            if(temp[j] == '#')      board[i][j] = 1;
            else if(temp[j] == '.') board[i][j] = 0;
            else if(temp[j] == 'J') { board[i][j] = 2; start = {i, j}; }
            else if(temp[j] == 'F') { board[i][j] = 3; fireStart = {i, j}; }
        }       
    }

    firebfs();

    int ans = bfs(start.first, start.second);

    if (ans != -1) {
        cout << ans << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }
}
