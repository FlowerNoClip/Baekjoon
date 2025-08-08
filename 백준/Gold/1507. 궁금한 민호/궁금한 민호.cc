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
void Init(int N, vector<vector<int>>& dist)
{
    for(int i = 0; i <N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> dist[i][j];
        }
    }
}
void Test(int N, vector<vector<int>>& dist)
{
    for(int i = 1; i <=N; i++)
    {
        for(int j = 1; j <=N; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    FAST_IO;
    int N;
    cin >> N;
    vector<vector<int>> dist(N, vector<int>(N));
    vector<vector<bool>> necessary(N, vector<bool>(N, true)); 
    Init(N, dist);

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j || i == k || j == k) continue;

                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    cout << -1;
                    return 0; 
                }

                if (dist[i][j] == dist[i][k] + dist[k][j]) {
                    necessary[i][j] = false; 
                }
            }
        }
    }

    int total = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (necessary[i][j]) {
                total += dist[i][j];
            }
        }
    }

    cout << total;
    return 0;
}