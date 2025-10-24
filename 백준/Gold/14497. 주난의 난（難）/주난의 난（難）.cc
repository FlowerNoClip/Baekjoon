#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);

int main() {
    FAST_IO;

    int n, m;
    int y1_, x1_, y2_, x2_; 
    cin >> n >> m;
    cin >> y1_ >> x1_ >> y2_ >> x2_;
    y1_--; x1_--; y2_--; x2_--;
    
    const int dx[] = {0, 0, 1, -1};
    const int dy[] = {1, -1, 0, 0};
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> visited(n, vector<int>(m, 0));

    queue<pair<int, int>> q;
    q.push({y1_, x1_});
    visited[y1_][x1_] = 1;
    int cnt = 0;
    while(a[y2_][x2_] != '0')
    {
        cnt++;
        queue<pair<int, int>> next_q;
        while(q.size())
        {
            auto[y,x] = q.front(); q.pop();
            for(int i = 0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny >= n || ny < 0 || nx >= m || nx < 0 || visited[ny][nx]) continue;

                visited[ny][nx] = cnt;

                if(a[ny][nx] != '0')
                {
                    next_q.push({ny, nx});
                    a[ny][nx] = '0';
                }
                else
                {
                    q.push({ny, nx});
                }
            }
        }
        q = move(next_q);
    }

    cout << visited[y2_][x2_] << endl;
    return 0;
}
