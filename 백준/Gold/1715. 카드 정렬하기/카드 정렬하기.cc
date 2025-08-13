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
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    int N; cin >> N;
    if (!N) return 0;

    if (N <= 1) { 
        cout << 0 << '\n';
        return 0;
    }
    for(int i = 0 ; i < N; i++)
    {
        ll temp; cin >> temp;
        pq.push(temp);
    }
    long long sum = 0;
    while(pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        long long c = a + b;
        sum += c;
        pq.push(c);
    }

    cout << sum;


}