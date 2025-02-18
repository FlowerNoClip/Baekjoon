#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int H, M;
    cin >> H >> M;

    M -= 45;  // 45분 빼기
    if (M < 0) {  // 분이 0보다 작으면
        M += 60;  // 60분을 더하고
        H--;      // 1시간 줄이기
        if (H < 0) {  // 시간이 0보다 작으면
            H = 23;  // 23으로 설정
        }
    }

    cout << H << " " << M;  // 결과 출력
    return 0;
}
