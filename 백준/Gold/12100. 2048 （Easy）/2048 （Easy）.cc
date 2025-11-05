#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int n, board[24][24], ret = 0;
void rotate(int board[24][24])
{
    int temp[24][24];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            temp[i][j] = board[n-1-j][i];
        }
    }
    memcpy(board,temp,sizeof(temp));
}
void slide(int board[24][24])
{
    int temp[24][24];
    memset(temp, 0, sizeof(temp));
    for(int i = 0; i < n; i++)
    {
        int cnt = 0;
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == 0) continue;

            if(board[i][j] == temp[i][cnt]) 
            {
                temp[i][cnt] *= 2;
                cnt++;
            }
            else if(temp[i][cnt] == 0)
            {
                temp[i][cnt]=board[i][j];
            }
            else
            {
                cnt++;
                temp[i][cnt] = board[i][j];
            }
        }
    }
    memcpy(board, temp, sizeof(temp));
}

void counting(int board[24][24])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ret = max(ret, board[i][j]);
        }
    }
}

void go(int depth, int board[24][24])
{
    if(depth == 5)
    {
        counting(board);
        return;
    }
    for(int i = 0; i < 4; i++)
    {
        int cpy[24][24];
        memcpy(cpy, board, sizeof(cpy));
        slide(cpy);
        go(depth+1, cpy);
        rotate(board);
    }
}
int main() {
    FAST_IO
    cin >> n;  
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> board[i][j];
        }
    }

    go(0, board);

    cout << ret;

    return 0;
}
