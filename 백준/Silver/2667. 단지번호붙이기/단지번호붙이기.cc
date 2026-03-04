#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
int dfs(int y, int x, vector<vector<int>> &board, vector<vector<bool>> &visited,int &cnt)
{
    visited[y][x] = true;
    cnt++;
    for(int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= 0 && ny < board.size() && nx >= 0 && nx < board[0].size())
        {
            if(!visited[ny][nx] && board[ny][nx] == 1)
            {
                dfs(ny,nx,board,visited,cnt);
                visited[ny][nx] = 1;   
            }
        }
    }
    return cnt;
}
int main()
{
    FAST_IO
    int N;
    cin >> N;
    vector<vector<int>> board(N,vector<int>(N,0));
    vector<vector<bool>> visited(N,vector<bool>(N,false));
    int allDie = 0;
    for(int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for(int j = 0; j < temp.size(); j++)
        {
            int a = temp[j] - '0';
            board[i][j] = a;
        }
    }
    vector<int> result;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(!visited[i][j] && board[i][j] == 1)
            {
                allDie++;
                int cnt = 0;
                result.push_back(dfs(i,j,board,visited,cnt));
            }
        }
    }
    sort(result.begin(), result.end());
    cout << allDie<< '\n';
    for(int tempInt : result)
    {
        cout << tempInt << '\n';
    }
}