#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};
int main()
{
    FAST_IO
    int T, M, N, K;
    cin >> T;
    while(T--)
    {
        queue<pair<int, int>> q;
        cin >> M >> N >> K;
        vector<vector<int>> plow(N, vector<int>(M));
        vector<vector<bool>> visited(N, vector<bool>(M));
        int x, y;
        for(int i = 0; i < K; i++)
        {
            cin >> x >> y;
            plow[y][x] = 1;
        }
        int cnt = 0;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(plow[i][j] == 1 && !visited[i][j])
                {
                    cnt++;
                    q.push({i,j});
                    while(!q.empty())
                    {
                        
                        auto[y,x] = q.front();
                        visited[y][x] = true;
                        q.pop();
                        for(int i = 0; i < 4; i++)
                        {
                            int ny = y + dy[i];
                            int nx = x + dx[i];
                            if(ny >= 0 && ny < N && nx >= 0 && nx < M)
                            {
                                if(!visited[ny][nx] && plow[ny][nx] == 1)
                                {
                                    visited[ny][nx] = true;
                                    q.push({ny,nx});
                                }
                            }
                        }         
                    }
                }
            }
        }

        cout << cnt << '\n';
    }
}