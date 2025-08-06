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
    vector<ll> arr(1002);

    arr[0] = 1;
    arr[1] = 2;
    for(int i = 2; i < arr.size(); i++)
    {
        arr[i] = (arr[i-1] + arr[i-2]) % 10007;
    }

    cout << arr[N-1];

}