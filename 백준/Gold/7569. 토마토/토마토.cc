#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <queue> 
#include <deque> 
#include <iterator> 
#include <list> 
#include <stack> 
#include <map> 
#include <unordered_map>
#include <set> 
#include <unordered_set>
#include <math.h> 
#define ll long long 
#define INF 1e9+10 
using namespace std;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int answer = 0;
struct StartVector
{
    int h;
    int n;
    int m;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int M, N, H;
    cin >> M >> N >> H;

    vector<vector<vector<int>>> arr(H, vector<vector<int>>(N, vector<int>(M)));
    vector<vector<vector<bool>>> visited(H, vector<vector<bool>>(N, vector<bool>(M, false)));
    queue<StartVector> sq;
    for (int h = 0; h < H; ++h) {
        for (int n = 0; n < N; ++n) {
            for (int m = 0; m < M; ++m) {
                cin >> arr[h][n][m];
                if (arr[h][n][m] == -1)
                {
                    visited[h][n][m] = true;
                }
                else if (arr[h][n][m] == 1)
                {
                    sq.push({ h, n, m });
                }
            }
        }
    }


    while (!sq.empty()) {
        int size = sq.size();
        bool spread = false;

        for (int i = 0; i < size; i++) {
            StartVector cur = sq.front();
            sq.pop();

            for (int j = 0; j < 6; j++) {
                int nx = cur.h + dx[j];
                int ny = cur.n + dy[j];
                int nz = cur.m + dz[j];

                if (nx >= 0 && nx < H && ny >= 0 && ny < N && nz >= 0 && nz < M &&
                    !visited[nx][ny][nz] && arr[nx][ny][nz] == 0) {

                    visited[nx][ny][nz] = true;
                    arr[nx][ny][nz] = 1;
                    sq.push({ nx, ny, nz });
                    spread = true;
                }
            }
        }

        if (spread) answer++;
    }

    for (int h = 0; h < H; ++h) {
        for (int n = 0; n < N; ++n) {
            for (int m = 0; m < M; ++m) {
                if (arr[h][n][m] == 0)
                {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }

    cout << answer;
}
