#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {1, -1, 0, 0};
struct Node {
    int y, x, dist, broken; 
};
int visited[1001][1001][2];
int main()
{
    FAST_IO
    int N, M; cin >> N >> M;
    vector<string> board(N);
    
    for(int i = 0; i < N; i++)
    {
        string temp; cin >> board[i];
    }
    queue<Node> q;
    q.push({0,0,1,0});
    visited[0][0][0] = 1;
    while(!q.empty())
    {
        Node curr = q.front();
        q.pop();

        if(curr.y == N-1 && curr.x == M-1)
        {
            cout << curr.dist;
            return 0;
        }
        for(int i = 0; i < 4; i++)
        {
            int ny = dy[i] + curr.y;
            int nx = dx[i] + curr.x; 
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

            if(board[ny][nx] == '0' && !visited[ny][nx][curr.broken])
            {
                visited[ny][nx][curr.broken] = 1;
                q.push({ny, nx, curr.dist + 1, curr.broken});
            }
            else if(board[ny][nx] == '1' && curr.broken == 0 && !visited[ny][nx][1])
            {
                visited[ny][nx][1] = 1;
                q.push({ny, nx, curr.dist+1, 1});
            }

        }
    }
        
    cout << -1;
    return 0;
}