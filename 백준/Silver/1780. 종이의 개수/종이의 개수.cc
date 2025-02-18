#include <iostream>
#include <vector>
#include <string>
using namespace std;
int mOneCnt = 0;
int zeroCnt = 0;
int oneCnt = 0;

void Triple(int x, int y, int N, vector<vector<int>>& S) {
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
        if (temp == -1) {
            mOneCnt++;
        }
        else if (temp == 0) {
            zeroCnt++;
        }
        else {
            oneCnt++;
        }

        
    }
     else {
         int half = N / 3;
         Triple(x, y, half, S);                // 좌상
         Triple(x + half, y, half, S);                // 좌중
         Triple(x + half * 2, y , half, S);   // 우상     
         Triple(x, y + half, half, S);   // 우상  
         Triple(x + half, y + half, half, S);   // 우상  
         Triple(x + half * 2, y + half, half, S);   // 우상  
         Triple(x, y + half * 2, half, S);         // 좌하
         Triple(x + half, y + half * 2, half, S);  // 우하
         Triple(x + half * 2, y + half * 2, half, S);  // 우하
        }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<vector<int>> S(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
        }
    }
    Triple(0, 0, N, S);
    cout << mOneCnt << endl << zeroCnt << endl << oneCnt << endl;
    return 0;
}
