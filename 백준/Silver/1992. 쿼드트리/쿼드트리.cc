#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
string str = "";

bool same(int y, int x, int ty, int tx, vector<vector<int>> & board)
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
    if(ty -y == 1 && tx - x == 1)
    {
        str += to_string(board[y][x]);
        return;
    }
    if(same(y,x,ty,tx,board))
    {
        str += to_string(board[y][x]);
        return;
    }
        int midY = (y + ty) / 2;
        int midX = (x + tx) / 2;
        str += '(';
        quadTree(y, x, midY, midX, board); 
        quadTree(y, midX, midY, tx, board); 
        quadTree(midY, x, ty, midX, board);
        quadTree(midY, midX, ty, tx, board);
        str += ')';
}
int main()
{
    int N; cin >> N;
    vector<vector<int>> board(N, vector<int>(N));
    for(int i = 0; i < N; i++)
    {
        string temp; cin >> temp;
        for(int j = 0; j < N; j++)
        {
            board[i][j] = temp[j]-'0';
        }
    }

    quadTree(0, 0, N, N, board);
    cout << str << endl;
}