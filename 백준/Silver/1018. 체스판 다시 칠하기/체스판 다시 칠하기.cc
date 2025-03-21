#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int checkboard(int x, int y, vector<vector<int>>& board) {
    int startColor = board[x][y]; // 시작 색상
    int cnt = 0;

    for (int i = x; i < x + 8; i++) {
        for (int j = y; j < y + 8; j++) {
            if ((i + j) % 2 == 0 && board[i][j] != startColor) {
                cnt++;
            }
            else if ((i + j) % 2 == 1 && board[i][j] == startColor) {
                cnt++;
            }
        }
    }
    return cnt;
}

int checkboardReverse(int x, int y, vector<vector<int>>& board) {
    int startColor = 1 - board[x][y]; // 시작 색 반전
    int cnt = 0;

    for (int i = x; i < x + 8; i++) {
        for (int j = y; j < y + 8; j++) {
            if ((i + j) % 2 == 0 && board[i][j] != startColor) {
                cnt++;
            }
            else if ((i + j) % 2 == 1 && board[i][j] == startColor) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y;
    cin >> x >> y;
    char temp;
    vector<vector<int>> board(x, vector<int>(y));
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> temp;
            board[i][j] = (temp == 'W') ? 0 : 1; // W=0, B=1
        }
    }

    int minCost = INT_MAX;
    for (int i = 0; i <= x - 8; i++) {
        for (int j = 0; j <= y - 8; j++) {
            int cost = min(checkboard(i, j, board), checkboardReverse(i, j, board));
            if (minCost > cost) {
                minCost = cost;
            }
        }
    }

    cout << minCost << "\n";
    return 0;
}
