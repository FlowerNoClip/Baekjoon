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
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define INF 1e9+10 
using namespace std;
int N,M;
vector<int> arr;
void backtrack() {
    if (arr.size() == M) {
        for (int num : arr) cout << num << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++) {
        arr.push_back(i);
        backtrack(); // 단순히 다음 깊이로
        arr.pop_back();
    }
}
int main() {
    FAST_IO;
    cin >> N >> M;
    backtrack();
}