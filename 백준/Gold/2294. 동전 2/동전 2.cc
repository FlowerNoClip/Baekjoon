#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 101;
const int MAX_K = 10001;
const int IMPOSSIBLE = 1000000000;

int N, K, cost[MAX_N], dp[MAX_N][MAX_K];

// 동전 개수를 구하는 함수
int coin(int n, int k) {
    if (k == 0) return 0;            // 목표 금액을 채우면 동전 개수는 0
    if (n == N) return IMPOSSIBLE;   // 동전 종류를 다 써도 목표 금액을 채우지 못함
    if (dp[n][k] != -1) return dp[n][k]; // 이미 계산된 값

    // 현재 동전을 사용하지 않은 경우
    int result = coin(n + 1, k);

    // 현재 동전을 사용할 수 있는 경우 (동전 재사용 가능)
    if (k >= cost[n]) {
        result = min(result, coin(n, k - cost[n]) + 1);
    }

    dp[n][k] = result;
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K; // N: 동전 종류 수, K: 목표 금액

    for (int i = 0; i < N; i++) {
        cin >> cost[i];
    }

    // dp 배열 초기화
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            dp[i][j] = -1;
        }
    }

    int result = coin(0, K);
    if (result == IMPOSSIBLE) {
        cout << "-1" << endl;
    }
    else {
        cout << result << endl;
    }
}
