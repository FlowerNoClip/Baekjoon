#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX_LEN 91
using namespace std;

long long dp[MAX_LEN] = { 1 };


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[N];
}
 