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
vector<bool> used(100, false);
void backtrack(int depth) {
    if (arr.size() == M) {
        for (int num : arr)
        cout << num << " ";
        cout << "\n";
        return;
    }

    for (int i = depth; i <= N; i++) {
        arr.push_back(i);
        backtrack(i);
        arr.pop_back();
    }
}
int main() {
    FAST_IO;
    cin >> N >> M;
    backtrack(1);
}