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
int N, M;
vector<vector<int>> arr;

int bfs(int start) {
    vector<int> distance(N + 1, INF);
    queue<int> q;

    q.push(start);
    distance[start] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next : arr[current]) {
            if (distance[next] == INF) { // 아직 방문하지 않은 경우
                distance[next] = distance[current] + 1;
                q.push(next);
            }
        }
    }

    // 각 노드까지의 거리 합 반환 (케빈 베이컨 수)
    int total_distance = 0;
    for (int i = 1; i <= N; i++) {
        total_distance += distance[i];
    }
    return total_distance;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    arr.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    int min_bacon = INF;
    int person = -1;

    for (int i = 1; i <= N; i++) {
        int bacon = bfs(i);
        if (bacon < min_bacon) {
            min_bacon = bacon;
            person = i;
        }
    }

    cout << person << endl;
}
