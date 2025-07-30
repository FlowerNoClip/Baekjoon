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
    int N, K; cin >> N >> K;
    vector<int> arr(N);
    for(int& num : arr) cin >> num;

    int left = 0; int right = 0; int sum = 0; int cnt = 0;

    while (true) {
        if (sum >= K) 
        {
            if(sum == K) cnt++;
            sum -= arr[left++];
        } 
        else 
        {
            if (right == N) break;
            sum += arr[right++];
        }
    }

    cout << cnt;
}
