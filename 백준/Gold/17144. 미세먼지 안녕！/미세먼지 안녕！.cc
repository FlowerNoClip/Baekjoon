#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int height, width, tc;
int dx[] = {0, 0, 1, -1};  // 동서남북 순서 수정할 필요 없음
int dy[] = {1, -1, 0, 0};

inline bool isValid(int y, int x) {
    return (y >= 0 && y < height && x >= 0 && x < width);
}

int main() {
    FAST_IO;
    cin >> height >> width >> tc;

    vector<vector<int>> board(height, vector<int>(width));
    int cleanerTop = -1, cleanerBottom = -1;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> board[i][j];
            if (board[i][j] == -1) {
                if (cleanerTop == -1) cleanerTop = i;
                else cleanerBottom = i;
            }
        }
    }

    while (tc--) {
        vector<vector<int>> temp(height, vector<int>(width, 0));
        temp[cleanerTop][0] = temp[cleanerBottom][0] = -1;

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (board[y][x] <= 0) continue; 
                int spread = board[y][x] / 5;
                int cnt = 0;
                for (int i = 0; i < 4; i++) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if (isValid(ny, nx) && board[ny][nx] != -1) {
                        temp[ny][nx] += spread;
                        cnt++;
                    }
                }
                temp[y][x] += board[y][x] - spread * cnt;
            }
        }

        board = temp;

        for (int i = cleanerTop - 1; i > 0; i--) board[i][0] = board[i - 1][0];
        for (int j = 0; j < width - 1; j++) board[0][j] = board[0][j + 1];
        for (int i = 0; i < cleanerTop; i++) board[i][width - 1] = board[i + 1][width - 1];
        for (int j = width - 1; j > 1; j--) board[cleanerTop][j] = board[cleanerTop][j - 1];
        board[cleanerTop][1] = 0;

        for (int i = cleanerBottom + 1; i < height - 1; i++) board[i][0] = board[i + 1][0];
        for (int j = 0; j < width - 1; j++) board[height - 1][j] = board[height - 1][j + 1];
        for (int i = height - 1; i > cleanerBottom; i--) board[i][width - 1] = board[i - 1][width - 1];
        for (int j = width - 1; j > 1; j--) board[cleanerBottom][j] = board[cleanerBottom][j - 1];
        board[cleanerBottom][1] = 0;

        board[cleanerTop][0] = board[cleanerBottom][0] = -1;
    }

    int sum = 0;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if (board[i][j] > 0) sum += board[i][j];

    cout << sum << "\n";
}
