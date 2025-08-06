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
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define INF 1e9+10 
const ll LLINF = 2e9 + 1;
using namespace std;
struct Edge
{
    int to;
    int cost;
};
vector<int> dijkstra(int start, vector<vector<Edge>>& graph) {
    vector<int> dist(graph.size(), INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (cost > dist[cur]) continue;
        for (auto& next : graph[cur]) {
            int newCost = cost + next.cost;
            if (newCost < dist[next.to]) {
                dist[next.to] = newCost;
                pq.push({newCost, next.to});
            }
        }
    }
    return dist;
}
int main() {
    FAST_IO;
    int V, E, start;
    cin >> V >> E >> start;
    vector<vector<Edge>> graph(V+1), reverseGraph(V+1);
    for(int i = 0 ; i < E; i ++)
    {
        int u, v, w; cin >> u >> v >> w;
        graph[u].push_back({v,w});
        reverseGraph[v].push_back({u, w}); // 간선 뒤집기
    }

    vector<int> distFromX = dijkstra(start, graph);        // X → 마을
    vector<int> distToX = dijkstra(start, reverseGraph);   // 마을 → X

    int answer = 0;
    for (int i = 1; i <= V; i++) {
        answer = max(answer, distToX[i] + distFromX[i]);
    }

    cout << answer;
}