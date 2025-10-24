#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, m;

inline bool inb(int y, int x) { return 0 <= y && y < n && 0 <= x && x < m; }

int main() {
    FAST_IO;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m, 0));
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];

    pair<int,int> s1{-1,-1}, s2{-1,-1};

    queue<pair<int,int>> waterQ, waterNext;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'X') a[i][j] = 1;
            else {
                a[i][j] = 0;
                waterQ.push({i, j});           // 현재 물은 모두 물 큐에 (초기 경계 형성용)
            }
            if (g[i][j] == 'L') {
                if (s1.first == -1) s1 = {i, j};
                else                s2 = {i, j};
            }
        }
    }

    queue<pair<int,int>> swanQ, swanNext;
    vector<vector<char>> swanVis(n, vector<char>(m, 0));
    swanQ.push(s1);
    swanVis[s1.first][s1.second] = 1;

    int day = 0;
    while (true) {
    
        bool meet = false;
        while (!swanQ.empty()) {
            auto [y, x] = swanQ.front(); swanQ.pop();
            if (y == s2.first && x == s2.second) { meet = true; break; }

            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d], nx = x + dx[d];
                if (!inb(ny, nx) || swanVis[ny][nx]) continue;
                swanVis[ny][nx] = 1;
                if (a[ny][nx] == 0) {
                    swanQ.push({ny, nx});
                } else {
                    swanNext.push({ny, nx});
                }
            }
        }
        if (meet) { cout << day << "\n"; return 0; }

        int wqsz = (int)waterQ.size();
        while (wqsz--) {
            auto [y, x] = waterQ.front(); waterQ.pop();
            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d], nx = x + dx[d];
                if (!inb(ny, nx)) continue;
                if (a[ny][nx] == 1) {
                    a[ny][nx] = 0;
                    waterNext.push({ny, nx});
                }
            }
        }

        swanQ = move(swanNext);
        waterQ = move(waterNext);
        day++;

    }
}
