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
#define ll long long 
#define INF 1e9+10 
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    vector<int> arr(N);
    vector<int> dp(N, 1);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int lis_length = *max_element(dp.begin(), dp.end());
    cout << lis_length << '\n';
}
