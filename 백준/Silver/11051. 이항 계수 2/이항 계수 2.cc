#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define MAX 1001
using namespace std;

void bincoeff(int n, int k, vector<vector<long long>>& B) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || i == 0) {
                B[i][j] = 1;
            }
            else {
                B[i][j] = (B[i - 1][j - 1] + B[i - 1][j]) % 10007;
            }
        }
    }

   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);       
    vector<vector<long long>> A2(MAX, vector<long long>(MAX, 0));

    int N, K;
    cin >> N >> K;
    bincoeff(N, K, A2);
    cout << A2[N][K]<< endl;




}
