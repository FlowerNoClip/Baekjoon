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
int N, M;
vector<vector<int>> dist;
void Init()
{
    dist.assign(N+1, vector<int>(N+1, INF));
    for(int i = 1; i <= N; i++)
    {
        dist[i][i] = 0;
    }
}
void Floyd() 
{
    for(int mid = 1; mid <= N; mid++)
    {
        for(int start = 1; start <= N; start++)
        {
            for(int end = 1; end <= N; end++)
            {
                if(dist[start][end] > dist[start][mid] + dist[mid][end])
                {
                    dist[start][end] = dist[start][mid] + dist[mid][end];
                }
            }
        }
    }
}
void PrintFloyd()
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <=N; j++)
        {
            if (dist[i][j] == INF) cout << "0 ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}
int main() {
    FAST_IO;
    cin >> N >> M;
    Init();

    for(int i = 0; i < M; i++)
    {
        int u,v,w; cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        
    }
    
    Floyd();
    PrintFloyd();
}