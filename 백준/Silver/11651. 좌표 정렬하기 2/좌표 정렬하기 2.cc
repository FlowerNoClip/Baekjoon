#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct coordinate {
    int x;
    int y;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    vector<coordinate> arr(T);
    for (int i = 0; i < T; i++) {
        cin >> arr[i].x >> arr[i].y;
    }

    // 정렬: y 기준 오름차순, y가 같으면 x 기준 오름차순
    sort(arr.begin(), arr.end(), [](const coordinate& a, const coordinate& b) {
        if (a.y == b.y) return a.x < b.x; // y가 같으면 x 기준
        return a.y < b.y; // y 기준
    });

    for (int i = 0; i < T; i++) {
        cout << arr[i].x << " " << arr[i].y << "\n";
    }

    return 0;
}
