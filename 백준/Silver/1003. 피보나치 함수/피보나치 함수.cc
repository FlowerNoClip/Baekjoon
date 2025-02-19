#include <iostream>
using namespace std;

int zero[41] = {0};  // fibonacci(n)에서 0이 출력된 횟수를 저장
int one[41] = {0};   // fibonacci(n)에서 1이 출력된 횟수를 저장

void fibonacci() {
    zero[0] = 1;  // fibonacci(0) 호출 시 0이 1번 출력
    one[0] = 0;   // fibonacci(0)에서는 1이 출력되지 않음

    zero[1] = 0;  // fibonacci(1) 호출 시 0은 출력되지 않음
    one[1] = 1;   // fibonacci(1) 호출 시 1이 1번 출력

    for (int i = 2; i <= 40; i++) {
        zero[i] = zero[i - 1] + zero[i - 2];  // fibonacci(n)에서 0이 출력된 횟수
        one[i] = one[i - 1] + one[i - 2];     // fibonacci(n)에서 1이 출력된 횟수
    }
}

int main() {
    int T;
    cin >> T;  // 테스트 케이스 수 입력

    fibonacci();  // fibonacci 수열 계산

    while (T--) {
        int n;
        cin >> n;  // 테스트 케이스마다 n 입력
        cout << zero[n] << " " << one[n] << endl;  // 각 n에 대한 0과 1의 출력 횟수 출력
    }

    return 0;
}
