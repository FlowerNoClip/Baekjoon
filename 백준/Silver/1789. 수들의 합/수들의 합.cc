#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long N;
    cin >> N;

    long long sum = 0;  // 누적 합
    long long ans = 0;  // 정답 (숫자의 개수)

    for (long long i = 1; ; i++) { // 무한 루프
        if (sum + i > N) break;    // 다음 숫자를 더하면 N을 초과하면 종료
        sum += i;                  // 누적 합에 현재 숫자 더하기
        ans = i;                   // 숫자의 개수 갱신
    }

    cout << ans;                   // 결과 출력
    return 0;
}
