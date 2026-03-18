#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;
int ret = 0;
const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {1, -1, 0, 0};
vector<vector<int>> board;
void virus(vector<vector<int>> &tboard)
{
    
    queue<pair<int, int>> q;
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            if(tboard[i][j] == 2)
            {
                q.push({i,j});
            }
        }
    }

    while(!q.empty())
    {
        auto [y,x] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= 0 && ny < board.size() && nx >= 0 && nx < board[0].size())
            {
                if(tboard[ny][nx] == 0)
                {
                    tboard[ny][nx] = 2;
                    q.push({ny, nx});
                }
            }
        }
    }
}
int safe(vector<vector<int>> &tboard)
{
    int cnt = 0;
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            if(tboard[i][j] == 0)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

void makeWall(int wallNum)
{
    
    if(wallNum == 3)
    {
        vector<vector<int>> cBoard = board;
        virus(cBoard);
        ret = max(ret,safe(cBoard));
        return;
    }

    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            if(board[i][j] == 0)
            {
                board[i][j] = 1;
                makeWall(wallNum + 1);
                board[i][j] = 0;
            }
        }
    }
}
int main()
{
    FAST_IO
    int N, M; cin >> N >> M;
    board.assign(N, vector<int>(M,0));
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }
    makeWall(0);
    cout << ret << endl;
    // 1. 벽 3개 무조건 세우기
    // 2. 벽 세운 뒤 바이러스 퍼지기
    // 3. 바이러스 퍼지고 난 뒤에 안전영역 숫자 세기
    // 4. 반복

}