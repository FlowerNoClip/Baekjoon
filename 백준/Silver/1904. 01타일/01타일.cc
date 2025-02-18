#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX_LEN 1000001
using namespace std;


int dp[MAX_LEN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;

    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    }
    cout << dp[N];
}
 