#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    vector <int>S(N, 0);

    int i, j;
    int k = 0;
    for (int w = 0; w < M; w++) {
        cin >> i >> j >> k;
        for (int g = i - 1; g < j; g++) {
            S[g] = k;
        }
    }

    

    for (int i = 0; i < S.size(); i++) {
        cout << S[i] << " ";
    }


}
