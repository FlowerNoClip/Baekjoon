#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    int Q = 0;
    int D = 0;
    int N = 0;
    int P = 0;
    int ans = 0;
    for (int i = 0; i < T; i++) {
        int ans;
        cin >> ans;

        int Q = 0, D = 0, N = 0, P = 0;

        Q = ans / 25; // 25로 나눈 몫이 쿼터 개수
        ans %= 25;    // 남은 금액

        D = ans / 10; // 10으로 나눈 몫이 다임 개수
        ans %= 10;    // 남은 금액

        N = ans / 5;  // 5로 나눈 몫이 니켈 개수
        ans %= 5;     // 남은 금액

        P = ans / 1;  // 1로 나눈 몫이 페니 개수

        cout << Q << " " << D << " " << N << " " << P << endl;
    }


}
