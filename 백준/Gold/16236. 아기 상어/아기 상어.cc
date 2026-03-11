#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};
int sy, sx, sValue = 2, curEat = 0, N;
void serchFish(vector<vector<int>> &board, map<pair<int,int>,int> &uMap)
{
    vector<vector<int>> visited(N, vector<int>(N,0));
    queue<pair<int, int>> q;
    q.push({sy, sx});
    visited[sy][sx] = 1;
    while(!q.empty())
    {
        auto[y,x] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= 0 && ny < N && nx >= 0 && nx < N)
            {
                if(board[ny][nx] <= sValue && !visited[ny][nx])
                {
                    
                    visited[ny][nx] = visited[y][x] + 1;
                    q.push({ny, nx});
                    if(board[ny][nx] != 0 && board[ny][nx] != sValue)
                    uMap[{ny,nx}] = visited[ny][nx]-1;
                }
            }
        }
    }
}
vector<pair<pair<int, int>, int>> mapSort(map<pair<int,int>,int> &uMap)
{
    vector<pair<pair<int, int>, int>> vec(uMap.begin(), uMap.end());
    sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second) {
            return a.second < b.second;
        }
        if (a.first.first != b.first.first) {
            return a.first.first < b.first.first;
        }
        return a.first.second < b.first.second;
    });
    uMap.clear();
    return vec;
}
int main()
{
    cin >> N;
    vector<vector<int>> board(N,vector<int>(N));
    vector<vector<int>> visited(N,vector<int>(N));
    map<pair<int,int>,int> uMap;
    int ret = 0;
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 9)
            {
                sy = i;
                sx = j;
            }
        }
    }
    serchFish(board,uMap);
    while(true)
    {
        if(uMap.empty())
        {
            cout <<ret;
            return 0;
        }
        else
        {
            vector<pair<pair<int, int>, int>> vec = mapSort(uMap);
            auto it = vec.begin();
            curEat++;
            if(sValue == curEat)
            {
                sValue++;
                curEat = 0;
            }
            board[sy][sx] = 0;
            board[it->first.first][it->first.second] = 0;
            sy = it->first.first;
            sx = it->first.second;
            ret += it->second;
            vec.clear();
            serchFish(board,uMap);
        }
    }
    
}