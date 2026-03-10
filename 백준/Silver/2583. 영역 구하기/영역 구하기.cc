#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {1, -1, 0, 0};
int main()
{
    FAST_IO
    int M, N, K; cin >> M >> N >> K;
    vector<vector<int>> board(M, vector<int>(N, 0));
    vector<vector<bool>> visited(M, vector<bool>(N, false));



    for(int j = 0; j < K; j++)
    {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >>ry;
        for(int i = lx; i < rx; i++)
        {
            for(int q = ly; q < ry; q++)
            {
                board[q][i] = 1;
            }
        }
    }

    int cnt = 0;
    vector<int> ret;
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(board[i][j] == 0 && !visited[i][j])
            {
                int range = 1;
                cnt++;
                queue<pair<int, int>> q;
                q.push({i,j});
                visited[i][j] = true;
                while(!q.empty())
                {
                    auto[y,x] = q.front();
                    q.pop();
                    
                    for(int i = 0; i < 4; i++)
                    {
                        int ny = y + dy[i];
                        int nx = x + dx[i];
                        if(ny >= 0 && ny < M && nx >= 0 && nx < N)
                        {
                            if(!visited[ny][nx] && board[ny][nx] == 0)
                            {
                                range++;
                                visited[ny][nx] = true;
                                q.push({ny,nx});
                                
                            }
                        }
                    }
                }
                ret.push_back(range);
            }
        }
    }
    
    cout << cnt << '\n';

    sort(ret.begin(), ret.end());

    for(int a : ret)
    {
        cout << a << " ";
    }
    

}