#include <iostream>
#include <vector>
#include <string>
using namespace std;

void QuadTree(int x, int y, int N, vector<vector<int>> S) {
    bool isUniform = true;
    int temp = S[x][y];
    for (int i = x; i < x+N; i++) {
        for (int j = y; j < y+N; j++) {
            if (S[i][j] != temp) {
                isUniform = false;
                break;
            }
        }
        if (!isUniform) break;
    }
    if (isUniform) {
        cout << temp; 
    }
     else {
         cout << "("; // 영역 분할 시작
         int half = N / 2;
         QuadTree(x, y, half, S);                // 좌상
         QuadTree(x, y + half, half, S);         // 우상
         QuadTree(x + half, y, half, S);         // 좌하
         QuadTree(x + half, y + half, half, S);  // 우하
         cout << ")"; // 영역 분할 끝
        }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<vector<int>> S(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++) {
            S[i][j] = row[j] - '0';
        }
    }
    QuadTree(0, 0, N, S);
    return 0;
}
