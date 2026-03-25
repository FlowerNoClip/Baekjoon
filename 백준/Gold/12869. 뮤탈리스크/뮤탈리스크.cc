#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;
int N, visited[61][61][61], board[61][61][61], temp[3];

int damage[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {1, 9, 3},
    {1, 3, 9},
    {3, 1, 9},
    {3, 9, 1}
};
struct SCV {
    int a, b, c;
};

queue<SCV> q;
int bfs(int a, int b, int c)
{
    q.push({a,b,c});
    visited[a][b][c] = 1;
    while(!q.empty())
    {
        SCV t = q.front();
        q.pop();

        if(visited[0][0][0]) break;
        for(int i = 0; i < 6; i++)
        {
            int na = max(0, t.a - damage[i][0]);
            int nb = max(0, t.b - damage[i][1]);
            int nc = max(0, t.c - damage[i][2]);
            if(!visited[na][nb][nc])
            {
                visited[na][nb][nc] = visited[t.a][t.b][t.c] + 1;
                q.push({na, nb, nc});
            }
        }
    }

    return visited[0][0][0] - 1;
}
int main()
{
    FAST_IO
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> temp[i];
    }
    cout << bfs(temp[0], temp[1], temp[2]) << endl;

}