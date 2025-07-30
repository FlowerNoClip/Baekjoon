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
using namespace std;

int main() {
    FAST_IO;
    int T; cin >> T;
    while(T--)
    {
        int N, M, K; cin >> N >> M >> K;
        int cnt = 0;
        vector<int> arr(N);
        for(int& num:arr) cin >> num;
        vector<int> extended(arr.begin(), arr.end());
        extended.insert(extended.end(), arr.begin(), arr.end());
        if (M == N) {
            ll total = 0;
            for (int i = 0; i < N; ++i) total += arr[i];
            cout << (total < K ? 1 : 0) << '\n';
            continue;
        }
        ll tempsum = 0;
        for(int i = 0; i < M; i++)
        {
            tempsum += extended[i];
        }
        //if (tempsum < K) cnt++; 
        for(int i = M; i < N+M; ++i)
        {
            tempsum = tempsum - extended[i-M] + extended[i];
            if(tempsum < K) cnt++;
        }

        cout << cnt << endl; 
    }

}