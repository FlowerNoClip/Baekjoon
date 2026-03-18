#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;
vector<vector<int>> board;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int ret, preCnt;
bool isOk()
{
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            if(board[i][j] == 1)
            {
                return false;
            }
        }
    }
    return true;
}
void melt()
{
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(),false));
    vector<pair<int, int>> meltList;

    q.push({0,0});
    visited[0][0] = true;
    while(!q.empty())
    {
        auto[y,x] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny >= 0 && ny < board.size() && nx >= 0 && nx < board[0].size())
            {
                if(!visited[ny][nx] && board[ny][nx] == 0)
                {
                    q.push({ny,nx});
                    visited[ny][nx] = true;
                }
                else if(board[ny][nx] == 1)
                {
                    meltList.push_back({ny,nx});
                }
            }
        }
    }

    for(auto [y,x] : meltList)
    {
        board[y][x] = 0;
    }
}
int main()
{
    FAST_IO
    int N, M; cin >> N >> M;
    board.assign(N, vector<int>(M));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }
    while(true)
    {
        preCnt = 0;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(board[i][j] == 1)
                {
                    preCnt++;
                }
            }
        }
        melt();
        if(isOk())
        {
            ret++;
            break;
        }
        ret++;
    }
    cout << ret << endl << preCnt;


}