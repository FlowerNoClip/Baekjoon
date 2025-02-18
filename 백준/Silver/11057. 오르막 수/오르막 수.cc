#include <iostream>
using namespace std;

const int mod = 10007;
int dp[1001][10] = { 0 };

int main() {
    int N;
    cin >> N;

    // 초기값 설정
    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }

    // DP 테이블 채우기
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) {
                dp[i][j] = 1; // j == 0일 때는 항상 1
            }
            else {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod; // 모듈러 연산
            }
        }
    }

    // 결과 계산
    int result = 0;
    for (int i = 0; i < 10; i++) {
        result = (result + dp[N][i]) % mod; // 모듈러 연산
    }

    cout << result << endl;

    return 0;
}
