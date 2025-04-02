#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <math.h>
#define ll long long
#define INF 1e9+10
using namespace std;
int board[502][502];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, b;
    int ansTime = 1e9;
    int ansHeight = -1;
    cin >> n >> m >> b;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for (int h = 0; h <= 256; h++) {
        int inven = 0;
        int remove = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int diff = board[i][j] - h;
                if (diff < 0) inven -= diff;
                else remove += diff;
            }
        }

        if (remove + b >= inven) {
            int totalTime = 2 * remove + inven;
            if (ansTime >= totalTime) {
                ansTime = totalTime;
                ansHeight = h;
            }
        }
    }

    cout << ansTime << " " << ansHeight;

    // 이 코드는 타인의 블로그를 참고하였음
}