#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int map[128][128];
int w_cnt = 0, b_cnt = 0;
void paper(int x, int y, int n);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    paper(0, 0, N);
    cout << w_cnt << " " << b_cnt << endl;



}

void paper(int x, int y, int N) {
    int cnt = 0;
    for (int i = x; i < x + N; i++) {
        for (int j = y; j < y + N; j++) {
            if (map[i][j]) {
                cnt++;
            }
        }
    }
    if (!cnt) w_cnt++;
    else if (cnt == N * N) b_cnt++;
    else {
        paper(x, y, N / 2);  // left top
        paper(x, y + N / 2, N / 2); // right top
        paper(x + N / 2, y, N / 2); // left bottom
        paper(x + N / 2, y + N / 2, N / 2); // right bottom
    }
    return;    

}
