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
    vector<ll> arr(N);
    for (ll &a : arr) cin >> a;

    sort(arr.begin(), arr.end());
    int l = 0;
    int r = N - 1;
    int curl = 0, curr = N - 1;
    ll sum = LLINF;

    while (l < r) {
        ll temp = arr[l] + arr[r];
        if (abs(temp) < sum) {
            sum = abs(temp);
            curl = l;
            curr = r;
        }

        if (temp > 0) r--;
        else l++;
    }

    cout << arr[curl] << " " << arr[curr];
}