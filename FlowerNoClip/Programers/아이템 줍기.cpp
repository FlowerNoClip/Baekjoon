#include <bits/stdc++.h>
using namespace std;
int board[102][102] = {0};
int visited[102][102] = {0};
const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};
void Init(int lx, int ly, int ux, int uy)
{
    for(int i = ly; i <= uy; i++)
    {
        for(int j = lx; j <= ux; j++)
        {
            board[i][j] = 1;
        }
    }

}
void ReInit(int lx, int ly, int ux, int uy)
{
    
    for(int i = ly+1; i < uy; i++)
    {
        for(int j = lx+1; j < ux; j++)
        {
            board[i][j] = 0;
        }
    }
}
void Debug()
{
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            cout << board[i][j]<< " ";
        }
        cout << endl;
    }
}
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    for(int i = 0; i < rectangle.size(); i++)
    {
        int lx = rectangle[i][0] * 2;
        int ly = rectangle[i][1] * 2;
        int ux = rectangle[i][2] * 2;
        int uy = rectangle[i][3] * 2;
        
        Init(lx, ly, ux, uy); 
    }
    for(int i = 0; i < rectangle.size(); i++)
    {
        int lx = rectangle[i][0] * 2;
        int ly = rectangle[i][1] * 2;
        int ux = rectangle[i][2] * 2;
        int uy = rectangle[i][3] * 2;
        
        ReInit(lx, ly, ux, uy); 
    }
    
    queue<pair<int, int>> q;
    q.push({characterY * 2, characterX * 2});
    visited[characterY * 2][characterX * 2] = 1;
    while(!q.empty())
    {
        auto[y,x] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int ny = dy[i] + y;
            int nx = dx[i] + x;

            if(ny >= 0 && ny < 102 && nx >= 0 && nx < 102)
            {
                if(!visited[ny][nx] && board[ny][nx])
                {
                    visited[ny][nx] = visited[y][x]+1;
                    q.push({ny, nx});
                }
                if(ny == itemY * 2 && nx == itemX * 2)
                {
                    return visited[ny][nx]/2;
                }
            }

        }
    }
    //Debug();
    //return answer;
}