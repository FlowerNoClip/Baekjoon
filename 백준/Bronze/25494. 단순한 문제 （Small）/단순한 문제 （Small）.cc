#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    int sum = 0;
    vector <int> A(3);
    for (int n = 0; n < N; n++) {
        int sum = 0;

        // A 벡터에 값 입력
        for (int i = 0; i < 3; i++) {
            cin >> A[i];
        }

        // 세 가지 중첩 루프
        for (int i = 1; i <= A[0]; i++) {
            for (int j = 1; j <= A[1]; j++) {
                for (int k = 1; k <= A[2]; k++) {
                    // 조건문 수정
                    if ((i % j == j % k) && (j % k == k % i)) {
                        sum += 1;
                    }
                }
            }
        }

        cout << sum << endl;
    }

}
    



