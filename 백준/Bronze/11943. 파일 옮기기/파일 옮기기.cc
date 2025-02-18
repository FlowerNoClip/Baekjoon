#include <iostream>
#include <algorithm> // std::min 함수 사용을 위한 헤더

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int A, B;
    int C, D;

    cin >> A >> B;
    cin >> C >> D;

    // 첫 번째 바구니에서 사과만 남기려면
    int moves1 = B + C; // 첫 번째 바구니의 오렌지를 두 번째 바구니로 + 두 번째 바구니의 사과를 첫 번째 바구니로

    // 첫 번째 바구니에서 오렌지만 남기려면
    int moves2 = A + D; // 첫 번째 바구니의 사과를 두 번째 바구니로 + 두 번째 바구니의 오렌지를 첫 번째 바구니로

    // 두 경우 중 최소값을 출력
    cout << min(moves1, moves2) << endl;

    return 0;
}
