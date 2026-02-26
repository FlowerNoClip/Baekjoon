#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int check(int x, int y, vector<vector<int>>& board)
{
    int start = board[x][y];
    int cost = 0;
    for(int i = x; i < x + 8; i++)
    {
        for(int j = y; j < y+8; j++)
        {
            if((i+j) % 2 == 0 && board[i][j] != start)
            {
                cost++;
            }
            else if((i + j) % 2 == 1 && board[i][j] == start)
            {
                cost++;
            }  
        }
    }
    return cost;
}

int reverseCheck(int x, int y, vector<vector<int>>& board)
{
    int start = 1-board[x][y];
    int cost = 0;
    for(int i = x; i < x + 8; i++)
    {
        for(int j = y; j < y+8; j++)
        {
            if((i+j) % 2 == 0 && board[i][j] != start)
            {
                cost++;
            }
            else if((i + j) % 2 == 1 && board[i][j] == start)
            {
                cost++;
            }  
        }
    }
    return cost;
}

int main()
{
    FAST_IO
    int N, M;
    char temp;
    int result = 1e9;
    cin >> N >> M;
    vector<vector<int>> board(N,vector<int>(M));
    for(int i = 0; i < N; i++)
    {   
        for(int j = 0; j < M; j++)
        {
            cin >> temp;
            board[i][j] = (temp == 'W') ? 0 : 1;
        }
    }
    
    for(int i = 0; i <= N-8; i++)
    {
        for(int j = 0; j <= M-8; j++)
        {
            int cost = cost = min(check(i,j,board), reverseCheck(i,j,board));
            
            result = min(result, cost);
        }
    }
    cout << result;


    
}