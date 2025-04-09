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

    int N, M;
    cin >> N >> M;

    vector<int> board(101, 0);
    vector<bool> visited(101, false);

    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        board[u] = v;
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        board[u] = v;
    }

    queue<pair<int, int>> q; 
    q.push({ 1, 0 }); 
    visited[1] = true;

    while (!q.empty()) {
        int current = q.front().first;
        int moves = q.front().second;
        q.pop();

        if (current == 100) { 
            cout << moves << endl;
            return 0;
        }

        for (int i = 1; i <= 6; i++) { 
            int next = current + i;
            if (next > 100) continue;

            if (board[next] != 0) next = board[next]; 

            if (!visited[next]) { 
                visited[next] = true;
                q.push({ next, moves + 1 });
            }
        }
    }

    return 0;
}
