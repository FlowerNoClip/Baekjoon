#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
using namespace std;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void bfs(int depth, int startX, int startY, vector<vector<int>>& board, vector<vector<bool>>& visited)
{
    queue<pair<int,int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    while(q.size())
    {
        int x = q.front().first;
        int y = q.front().second;   
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
        if(nx < 0 || nx >= board.size() || ny < 0 || ny >= board.size()) continue;
        if(board[nx][ny] <= depth) continue;
        if(visited[nx][ny]) continue;
            q.push({nx, ny});            
            visited[nx][ny] = true;
        }
    }
}



int main()
{
    FAST_IO
    int N; cin >> N;
    vector<vector<int>> arr(N, vector<int>(N));
    vector<vector<bool>> visited(N, vector<bool> (N));
    int max_value = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int a; cin >> a;
            arr[i][j] = a;
            if(max_value < a)
            {
                max_value = a;
            }
        }
    }
    int answer = 0;
    
    for(int i = 0; i <= max_value; i++) {
        int cnt = 0;
        visited.assign(N, vector<bool>(N, false));
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                if(arr[j][k] > i && !visited[j][k]) {
                    cnt ++;
                    bfs(i, j, k, arr, visited);
                }
            }
        }
        answer = max(answer, cnt);
    }
    
        cout << answer;
}