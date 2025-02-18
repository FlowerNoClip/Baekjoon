#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    
    vector<vector<int>> DP(15, vector<int>(15, 0));
    for (int i = 0; i <= 14; i++) {
        DP[0][i] = i;
    }
    for (int i = 0; i <= 14; i++) {
        DP[i][0] = 0;
    }

    for (int i = 1; i <= 14; i++) {
        for (int j = 1; j <= 14; j++) {
            DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
        }        
    }
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tempX;
        int tempY;
        cin >> tempX >> tempY;
        cout << DP[tempX][tempY]<<endl;
    }
}
