#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T; // 테스트 케이스 개수 입력 받기

    for (int i = 1; i <= T; ++i) {
        int A, B;
        cin >> A >> B; // A와 B 입력 받기

        int sum = A + B; // A와 B의 합

        cout << "Case #" << i << ": " << A << " + " << B << " = " << A + B << endl;
    }

    return 0;
}
