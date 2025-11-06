#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int k, t;

void spin(vector<int>& g, int dir){
    if(dir == 1){
        for(int j = 7; j > 0; j--) swap(g[j], g[j-1]);
    }else if(dir == -1){
        for(int j = 0; j < 7; j++) swap(g[j], g[j+1]);
    }
}

void rotate(vector<vector<int>>& board, int a, int b)
{
    vector<int> dir(t, 0);
    dir[a] = b;

    for (int i = a; i < t - 1; i++) {
        if (board[i][2] != board[i + 1][6]) dir[i + 1] = -dir[i];
        else break;
    }
    for (int i = a; i > 0; i--) {
        if (board[i][6] != board[i - 1][2]) dir[i - 1] = -dir[i];
        else break;
    }
    for (int i = 0; i < t; i++) if (dir[i]) spin(board[i], dir[i]);
}

int main()
{
    FAST_IO;
    cin >> t;
    vector<vector<int>> board(t, vector<int>(8, 0));
    for(int i = 0; i < t; i++){
        string s; cin >> s;
        for(int j = 0; j < 8; j++) board[i][j] = s[j] - '0';
    }

    cin >> k;
    for(int i = 0; i < k; i++){
        int a, b; cin >> a >> b;
        rotate(board, a-1, b);
    }

    int score = 0;
    for(int i = 0; i < t; i++) score += board[i][0];
    cout << score;
}
