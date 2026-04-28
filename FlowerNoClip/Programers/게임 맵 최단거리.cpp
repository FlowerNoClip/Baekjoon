#include<bits/stdc++.h>
using namespace std;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

int solution(vector<vector<int>> maps)
{
    int answer = -1;
    int sy = 0, sx = 0, ty = maps.size(), tx = maps[0].size();
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size()));
    queue<tuple<int, int,int>> q;
    q.push({sy, sx, 1});
    visited[sy][sx] = 1;
    int sum = 0;
    while(!q.empty())
    {
        auto[y,x,dist] = q.front();
        q.pop();
        if(y == maps.size()-1 && x == maps[0].size()-1)
        {
            return dist;
        }
        
        for(int i = 0; i < 4; i++)
        {
            int ny = dy[i] + y;
            int nx = dx[i] + x;

            if(ny >= 0 && ny < maps.size() && nx >= 0 && nx < maps[0].size())
            {
                if(!visited[ny][nx] && maps[ny][nx])
                {
                    q.push({ny,nx,dist+1});
                    visited[ny][nx] = 1;
                }
            }
        }
    }
    return -1;
}