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

int N, M;
vector<int> selected;

void backtracking(int start) {
    if (selected.size() == M) { // M개의 숫자를 선택했으면 출력
        for (int num : selected) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i <= N; i++) { // 오름차순 유지
        selected.push_back(i); // 1을 먼저 넣고 
        backtracking(i + 1); // 다음 숫자 선택 // 2넣고 
        selected.pop_back(); // 백트래킹 (원상복구) // 1 뺴고 
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    backtracking(1); // 1부터 시작
    return 0;

}
