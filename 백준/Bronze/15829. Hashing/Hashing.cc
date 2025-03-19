#include <iostream>
#include <string>

using namespace std;

const int MOD = 1234567891;
const int R = 31;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    string str;
    cin >> str;

    long long answer = 0;
    long long power = 1; // r^i 값을 저장

    for (int i = 0; i < N; i++) {
        int value = str[i] - 'a' + 1; // a = 1, b = 2, ...
        answer = (answer + value * power) % MOD; // 모듈러 연산
        power = (power * R) % MOD; // r^i 값 갱신
    }

    cout << answer << '\n';

    return 0;
}
