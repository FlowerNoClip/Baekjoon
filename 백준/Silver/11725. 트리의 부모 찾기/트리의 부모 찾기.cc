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
void dfs(int start, vector<bool>& visited, vector<vector<int>>& graph, vector<int>& parent)
{
    visited[start] = true;

    // 현재 노드에서 연결된 다른 노드들에 대해 재귀적으로 dfs 호출
    for (int i = 0; i < graph[start].size(); i++)
    {
        int next = graph[start][i];
        if (!visited[next])
        {
            parent[next] = start;
            dfs(next, visited, graph, parent);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<vector<int>> graph(N + 1); 
    vector<bool> visited(N + 1, false);
    vector<int> parent(N + 1, 1);

    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, visited, graph, parent);

    for (int i = 2; i <= N; i++)
    {
        cout << parent[i] << "\n";

    }
    return 0;
}