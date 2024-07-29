#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<long> S(N, 0);
    vector<long> C(M, 0);
    long answer = 0;

    // 첫 번째 입력값
    cin >> S[0];

    // 나머지 입력값 누적
    for (int i = 1; i < N; i++) {
        int temp;
        cin >> temp;
        S[i] = S[i - 1] + temp;
    }

    // 나머지 값을 기반으로 나머지 배열 업데이트
    for (int i = 0; i < N; i++) {
        int remainder = S[i] % M;

        if (remainder == 0) {
            answer++;
        }

        C[remainder]++;
    }

    // 나머지 배열을 기반으로 조합 수를 계산
    for (int i = 0; i < M; i++) {
        if (C[i] > 1) {
            answer += C[i] * (C[i] - 1) / 2;
        }
    }

    cout << answer << "\n";
}
