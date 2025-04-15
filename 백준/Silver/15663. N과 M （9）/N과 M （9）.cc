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
vector<int> arr;
int check[10];

void backtracking(int start) {
    if (start == M) { // M개의 숫자를 선택했으면 출력
        for (int i = 0; i < M; i++)
        {
            cout << selected[i] << " ";
        }
        cout << "\n";
        return;
    }
    int last = 0;
    for (int i = 0; i < N; i++) { // 오름차순 유지
        if (check[i] == 0 && arr[i] != last)
        {
            selected[start] = arr[i];
            last = selected[start];
            check[i] = 1;
            backtracking(start + 1);
            check[i] = 0;
        }

    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    selected.resize(M);
    backtracking(0); // 1부터 시작
    return 0;

}
