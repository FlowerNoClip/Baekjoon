#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int dfs(int y, int x, vector<vector<int>> &board, vector<vector<int>> &state)
{
    if(state[y][x] == 2) return 0;
    if(state[y][x] == 1) return 1;

    state[y][x] = 1;

    int ny = y;
    int nx = x;

    if(board[y][x] == 1) ny--;
    else if(board[y][x] == 2) nx--;
    else if(board[y][x] == 3) ny++;
    else if(board[y][x] == 4) nx++;
    int res = dfs(ny, nx, board, state);
    state[y][x] = 2;
    return res;
}


int main()
{
    FAST_IO
    int N, M; cin >> N >> M;
    vector<vector<int>> board(N,vector<int>(M));
    vector<vector<int>> state(N,vector<int>(M));

    for(int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for(int j = 0; j < M; j++)
        {
            if(temp[j] == 'R')
            {
                board[i][j] = 4;
            }
            else if(temp[j] == 'L')
            {
                board[i][j] = 2;
            }
            else if(temp[j] == 'U')
            {
                board[i][j] = 1;
            }
            else if(temp[j] == 'D')
            {
                board[i][j] = 3;
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(!state[i][j])
            {
                cnt += dfs(i, j, board,state);
            }
        }
    }

    cout << cnt << endl;
}