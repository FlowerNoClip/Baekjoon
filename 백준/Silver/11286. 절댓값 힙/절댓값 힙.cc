#include <iostream>
#include <queue>
using namespace std;

struct Compare {
    bool operator()(int a, int b) {
        if (abs(a) == abs(b)) {
            return a > b; // 절댓값이 같으면, 원래 값 기준으로 오름차순
        }
        return abs(a) > abs(b); // 절댓값 기준 오름차순
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, Compare> pq;

    int T;
    cin >> T;

    while (T--) {
        int temp;
        cin >> temp;

        if (temp == 0) {
            if (pq.empty()) {
                cout << 0 << "\n";
            }
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else {
            pq.push(temp);
        }
    }

    return 0;
}