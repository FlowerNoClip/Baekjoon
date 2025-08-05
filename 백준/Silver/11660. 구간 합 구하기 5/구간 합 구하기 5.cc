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

int main() {
    FAST_IO;
    int N, M; cin >> N >> M;
    vector<vector<int>> arr(N+1, vector<int>(N+1));
    //vctor<vector<int>> prefix(N+1, vector<int>(N+1));
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            arr[i][j] = arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1] + arr[i][j];
        }
    }
    while (M--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << arr[x2][y2]
             - arr[x1-1][y2]
             - arr[x2][y1-1]
             + arr[x1-1][y1-1] << '\n';
    }
}