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
    FAST_IO
    int N, K;
    cin >> N >> K;

    vector<int> num(N);
    for(int& a : num) cin >> a;

    ll tempsum = 0;
    for(int i = 0; i < K; i++)
    {
        tempsum += num[i];
    }
    ll maxNum = tempsum;
    for(int i = K; i < N; i++)
    {
        tempsum = tempsum - num[i-K] + num[i];
        maxNum = max(maxNum, tempsum);
    }
    
    cout << maxNum;
    return 0;
}