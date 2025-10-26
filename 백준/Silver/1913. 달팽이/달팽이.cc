#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, key;
    if (!(cin >> N >> key)) return 0;

    vector<vector<int>> a(N, vector<int>(N, 0));

    int col = N / 2;
    int row = N / 2;
    int num = 1;


    
    for(int URDL = 1; num <= N*N; ++URDL)
    {
        for(int i = 1; i <= (URDL + 1) / 2; ++i)
        {
            a[col][row] = num++;
            if(num > N*N) break;

            if(URDL % 4 == 1) col--;
            else if(URDL % 4 == 2) row++;
            else if (URDL % 4 == 3) col++;
            else row--;
        }
    }
    // 표 출력
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << a[i][j] << (j + 1 == N ? '\n' : ' ');
        }
    }

    // key 좌표 찾기 (1-based)
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (a[i][j] == key) {
                cout << (i + 1) << ' ' << (j + 1) << '\n';
                return 0;
            }
        }
    }
    return 0;
}
