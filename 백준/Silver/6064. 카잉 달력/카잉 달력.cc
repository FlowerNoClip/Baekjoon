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
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T;
    int N, M, x, y;
    while (T--) {
        int N, M, x, y;
        cin >> N >> M >> x >> y;

        int year = x;
        bool found = false;

        while (year <= N * M) {
            if ((year - 1) % M + 1 == y) {
                cout << year << endl;
                found = true;
                break;
            }
            year += N;
        }

        if (!found) cout << "-1" << endl; // 답을 찾지 못한 경우
    }
}
