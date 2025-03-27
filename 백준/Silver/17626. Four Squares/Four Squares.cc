#include<vector>
#include<queue>
#include<algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int minSquares(int n) {
    vector<int> dp(n + 1, 1e9); // 큰 값으로 초기화
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int k = 1; k * k <= i; k++) {
            dp[i] = min(dp[i], dp[i - k * k] + 1);
        }
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << minSquares(n) << endl;
    return 0;
}