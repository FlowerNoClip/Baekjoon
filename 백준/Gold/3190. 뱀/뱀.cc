#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int main() {
    FAST_IO
    int n, k;
    cin >> n >> k;
    int ret = 0;
    vector<vector<int>> board(n, vector<int>(n));

    for (int i = 0; i < k; i++) {
        int y, x;
        cin >> y >> x;
        board[y - 1][x - 1] = 2; // 사과
    }

    cin >> k;
    vector<pair<int, char>> movement(k);
    for (int i = 0; i < k; i++)
        cin >> movement[i].first >> movement[i].second;

    int dir = 0;
    deque<pair<int, int>> snake;
    snake.push_front({0, 0});
    board[0][0] = 1;

    int prevTime = 0;
    for (int i = 0; i < movement.size(); i++) {
        int moveTime = movement[i].first - prevTime;
        prevTime = movement[i].first;

        for (int j = 0; j < moveTime; j++) {
            auto [y, x] = snake.front();
            int ny = y + dy[dir], nx = x + dx[dir];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n || board[ny][nx] == 1) {
                cout << ret + 1;
                return 0;
            }
            snake.push_front({ny, nx});
            if (board[ny][nx] != 2) {
                auto [by, bx] = snake.back();
                snake.pop_back();
                board[by][bx] = 0;
            }
            board[ny][nx] = 1;
            ret++;
        }

        if (movement[i].second == 'D') dir = (dir + 1) % 4;
        else if (movement[i].second == 'L') dir = (dir + 3) % 4;
    }


    while (true) {
        auto [y, x] = snake.front();
        int ny = y + dy[dir], nx = x + dx[dir];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n || board[ny][nx] == 1) {
            cout << ret + 1;
            return 0;
        }
        snake.push_front({ny, nx});
        if (board[ny][nx] != 2) {
            auto [by, bx] = snake.back();
            snake.pop_back();
            board[by][bx] = 0;
        }
        board[ny][nx] = 1;
        ret++;
    }
}
