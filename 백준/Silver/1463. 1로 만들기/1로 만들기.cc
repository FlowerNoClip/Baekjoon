#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX_LEN 1000001
using namespace std;

int dp[MAX_LEN];

int gop(int n) {
    if (n == 1) return 0;
    if (dp[n] != -1) return dp[n];
    int result = gop(n - 1) + 1;

    if (n % 3 == 0) result = min(result, gop(n / 3) + 1);
    if (n % 2 == 0) result = min(result, gop(n / 2) + 1);
    dp[n] = result;
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int X;
    cin >> X;
    fill(dp, dp + MAX_LEN, -1);
    cout << gop(X) << endl;
    
}
 