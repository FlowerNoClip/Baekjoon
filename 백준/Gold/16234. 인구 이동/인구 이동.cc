#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;
vector<vector<int>> board;
vector<vector<int>> visited;
int N, L, R;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
bool move_population() {
    visited.assign(N, vector<int>(N, 0));
    bool is_moved = false;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(!visited[i][j]) {
                vector<pair<int,int>> nodes;
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = 1;
                int sum = board[i][j];
                nodes.push_back({i, j});
                while(!q.empty())
                {
                    auto[y,x] = q.front();
                    q.pop();
                    for(int i = 0; i < 4; i++)
                    {
                        int ny = y + dy[i];
                        int nx = x + dx[i];
                        if(ny >= 0 && ny < N && nx >= 0 && nx < N)
                        if(!visited[ny][nx])
                        {

                            if(abs(board[ny][nx] - board[y][x]) >= L && abs(board[ny][nx] - board[y][x]) <= R)
                            {
                                q.push({ny,nx});
                                visited[ny][nx] = 1;
                                nodes.push_back({ny, nx});
                                sum += board[ny][nx];
                            }
                        }
                    }
                }

                
                if(nodes.size() > 1) {
                    is_moved = true;
                    int avg = sum / nodes.size();
                    for(auto p : nodes) board[p.first][p.second] = avg;
                }
            }
        }
    }
    return is_moved;
}

int main()
{
    FAST_IO
    cin >> N >> L >> R;
    board.assign(N, vector<int>(N));
    visited.assign(N, vector<int>(N));
    for(int i = 0 ; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }
    int day = 0;
    while(move_population())
    {
        day++;
    }
    cout << day;

}