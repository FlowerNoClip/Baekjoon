#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;

    int DP[1001][4];

    for (int i = 1; i <= N; i++) 
    {
        for (int j = 1; j <= 3; j++) 
        {
            cin >> DP[i][j];
        }
    }
    

    for (int i = 2; i <= N; i++) {
        DP[i][1] = DP[i][1] + min(DP[i - 1][2], DP[i - 1][3]);
        DP[i][2] = DP[i][2] + min(DP[i - 1][1], DP[i - 1][3]);
        DP[i][3] = DP[i][3] + min(DP[i - 1][1], DP[i - 1][2]);
    }

    cout << min({ DP[N][1], DP[N][2], DP[N][3]});

    return 0;
}
