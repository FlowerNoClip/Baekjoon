#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
string str = "";

bool same(int y, int x, int ty, int tx, vector<vector<int>>& board)
{
    int tempNum = board[y][x];
    for(int i = y; i < ty; i++)
    {
        for(int j = x; j < tx; j++)
        {
            if(tempNum != board[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
void quadTree(int y, int x, int ty, int tx, vector<vector<int>>& board)
{
    if(ty - y == 2 && tx - x == 2)
    {
        if(same(y,x,ty,tx,board))
        {
            str+= to_string(board[y][x]);
            return;
        }

    }
    if(same(y,x,ty,tx,board))
    {
        str += to_string(board[y][x]);
        return;
    }
        str += 'X';
        int halfY = (y+ty)/2;
        int halfX = (x+tx)/2;
        quadTree(y,x, halfY, halfX, board);
        quadTree(y,halfX, halfY, tx, board);
        quadTree(halfY,x, ty, halfX, board);
        quadTree(halfY,halfX, ty, tx, board);
}

int main()
{
    FAST_IO
    int N; cin >> N;
    vector<vector<int>> board(N, vector<int>(N));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    quadTree(0,0,N,N,board);

    cout << str;
}