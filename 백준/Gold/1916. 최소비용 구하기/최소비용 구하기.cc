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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    vector<vector<pair<int, int>>> graph(N + 1);
    vector<int> dist(N + 1, INF);

    for (int i = 0; i < M; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].emplace_back(to, cost);
    }

    int start, end;
    cin >> start >> end;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty())
    {
        int current_dist = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (current_dist > dist[current]) continue;

        for (auto& edge : graph[current])
        {
            int next = edge.first;
            int weight = edge.second;

            if (dist[next] > current_dist + weight)
            {
                dist[next] = current_dist + weight;
                pq.push({ dist[next], next });
            }
        }
    }
    cout << dist[end] << '\n';

}
