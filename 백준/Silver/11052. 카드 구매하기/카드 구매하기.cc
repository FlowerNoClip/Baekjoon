#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[1001];  // 카드 값 배열
int DP[1001]; // DP 배열

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];  // 1번 카드부터 입력 받기
    }
    
    // DP 초기화
    DP[0] = 0;  // 0개의 카드를 사용할 때는 0
    
    // DP 계산
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            DP[i] = max(DP[i], DP[i - j] + A[j]);
        }
    }
    
    cout << DP[N] << endl;
    return 0;
}
