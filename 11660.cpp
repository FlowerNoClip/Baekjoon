#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // C++ 표준 스트림과 C 표준 스트림의 동기화를 해제하여 입출력 성능을 높임
    cin.tie(NULL); // 입력과 출력을 묶지 않음으로써 성능 최적화
    cout.tie(NULL);

    int N, M;
    cin >> N >> M; // N은 배열 크기, M은 쿼리 수

    vector<vector<int>> A(N + 1, vector<int>(N + 1, 0)); // 1-based 인덱스를 사용하기 위해 N+1 크기의 2차원 배열 A 선언

    vector<vector<int>> D(N + 1, vector<int>(N + 1, 0)); // 누적 합을 저장할 2차원 배열 D 선언

    // 배열 A에 입력값을 저장하고, 누적 합 배열 D를 계산
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
            // D[i][j]는 (1,1)부터 (i,j)까지의 부분 행렬 합
            D[i][j] = D[i][j - 1] + D[i - 1][j] - D[i - 1][j - 1] + A[i][j];
        }
    }

    // M개의 쿼리 처리
    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2; // 각 쿼리의 좌표 (x1, y1), (x2, y2) 입력

        // D 배열을 사용하여 구간 합 계산
        // (x1, y1)부터 (x2, y2)까지의 구간 합은 다음과 같이 계산
        int result = D[x2][y2] - D[x1 - 1][y2] - D[x2][y1 - 1] + D[x1 - 1][y1 - 1];
        cout << result << endl; // 결과 출력
    }
}
