#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int dy[8] = {2, 2, 1, 1, -1, -1, -2, -2};
const int dx[8] = {1, -1, 2, -2, 2, -2, 1, -1};
int ret = 0;
int bfs(int y, int x, vector<vector<bool>> visited, int ty, int tx)
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{y, x}, 0});
    while(!q.empty())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        if(y == ty && x == tx) return dist;
        for(int i = 0; i < 8; i++)
        {

            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= 0 && ny < visited.size() && nx >= 0 && nx < visited[0].size() && !visited[ny][nx])
            {   
                visited[ny][nx] = true;
                q.push({{ny,  nx} , dist + 1});
            }
        }
    }

    return -1;    
}

int main()
{
    int T; cin >> T;
    while(T--)
    {
        int N; cin >> N;
        vector<vector<int>> board(N, vector<int>(N));
        vector<vector<bool>> visited(N, vector<bool>(N));
        
        int sy, sx, ty, tx; cin >> sy >> sx >> ty >> tx;
        cout << bfs(sy, sx,visited, ty, tx) << '\n';
    }

}