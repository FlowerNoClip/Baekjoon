#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

struct Cmd {
    int r, c, s;
};

void rotateClockwise(vector<vector<int>>& board, int r, int c, int s)
{
    r--; c--; // 1-based → 0-based
    for (int layer = 1; layer <= s; layer++)
    {
        int top = r - layer;
        int left = c - layer;
        int bottom = r + layer;
        int right = c + layer;

        int prev = board[top][left];

        // 위쪽 행 →
        for (int j = left + 1; j <= right; j++)
            swap(board[top][j], prev);

        // 오른쪽 열 ↓
        for (int i = top + 1; i <= bottom; i++)
            swap(board[i][right], prev);

        // 아래쪽 행 ←
        for (int j = right - 1; j >= left; j--)
            swap(board[bottom][j], prev);

        // 왼쪽 열 ↑
        for (int i = bottom - 1; i >= top; i--)
            swap(board[i][left], prev);
    }
}
int getMinRowSum(vector<vector<int>>& board)
{
    int ret = 1e9;
    for (auto& row : board)
        ret = min(ret, accumulate(row.begin(), row.end(), 0));
    return ret;
}

int main() {
    FAST_IO

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> board(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    vector<Cmd> cmd(k);
    for (int i = 0; i < k; i++)
        cin >> cmd[i].r >> cmd[i].c >> cmd[i].s;

    vector<int> order(k);
    iota(order.begin(), order.end(), 0); // 0~k-1
    int answer = 1e9;

    do {
        auto temp = board;
        for (int idx : order)
            rotateClockwise(temp, cmd[idx].r, cmd[idx].c, cmd[idx].s);
        answer = min(answer, getMinRowSum(temp));
    } while (next_permutation(order.begin(), order.end()));

    cout << answer;
    return 0;
}
