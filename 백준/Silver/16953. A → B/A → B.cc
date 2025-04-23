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
#include <unordered_map>
#include <set> 
#include <unordered_set>
#include <math.h> 
#define ll long long 
#define INF 1e9+10 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long A, B;
    cin >> A >> B;

    queue<pair<long long, int>> q;
    q.push({ A, 1 });

    while (!q.empty()) {
        long long cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur == B) {
            cout << cnt << '\n';
            return 0;
        }

        if (cur * 2 <= B) q.push({ cur * 2, cnt + 1 });
        if (cur * 10 + 1 <= B) q.push({ cur * 10 + 1, cnt + 1 });
    }

    cout << -1 << '\n';
    return 0;

}