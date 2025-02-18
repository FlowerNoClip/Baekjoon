#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define MAX 1001
using namespace std;
int N, K;
int DP[101][100001];
int W[101];
int V[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> W[i] >> V[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (j - W[i] >= 0) {
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - W[i]] + V[i]);
            }
            else {
                DP[i][j] = DP[i - 1][j];
            }
        }
    }

    cout << DP[N][K] << endl;




}
