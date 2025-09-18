#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int H, W;
    cin >> H >> W;

    vector<vector<int>> arr(H, vector<int>(W, -1));

    for (int i = 0; i < H; i++) {
        string s; cin >> s;
        int cloudPos = -1;
        for (int j = 0; j < W; j++) {
            if (s[j] == 'c') cloudPos = j;
            if (cloudPos != -1) arr[i][j] = j - cloudPos;
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}
