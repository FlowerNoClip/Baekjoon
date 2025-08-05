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
    int N; cin >> N;
    vector<int> arr(N);
    vector<int> temp;
    unordered_set<int> s;
    for(int& a : arr) cin >> a;
    int result = N;
    int L = 0; int R = 0;
    ll answer = 0;
    while(L < N)
    {
        while(R < N  && s.find(arr[R]) == s.end())
        {
            s.insert(arr[R]);
            R++;

            
        }
        answer +=(R-L);
        s.erase(arr[L]);
        L++;
    }

    cout << answer;
   }