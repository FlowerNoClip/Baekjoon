#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> dp(N + 1, 1e9); // dp[i]: i를 제곱수의 합으로 나타낼 때 최소 개수
    dp[0] = 0; // 0을 만드는 데 필요한 동전 개수는 0개

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j * j <= i; j++) { // j*j는 i 이하의 제곱수
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    cout << dp[N] << endl;
    return 0;
}
