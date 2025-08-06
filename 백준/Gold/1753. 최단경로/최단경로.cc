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
void dijkstra(int start, vector<vector<Edge>>& graph, vector<int>& dist) 
{
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty())
    {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(cost > dist[cur]) continue;

        for(auto& next : graph[cur])
        {
            int newCost = cost+next.cost;
            if(newCost < dist[next.to])
            {
                dist[next.to] = newCost;
                pq.push({newCost, next.to});
            }
        }
    }
}
int main() {
    FAST_IO;
    int V, E, N; cin >> V >> E >> N;
    vector<vector<Edge>> graph(V+1);

    for(int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
    }
    vector<int> dist(V+1, INF);
    dijkstra(N, graph, dist);
    for(int i = 1; i <= V; i++)
    {
        if(dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}