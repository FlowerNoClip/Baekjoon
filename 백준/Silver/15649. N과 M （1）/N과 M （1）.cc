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

void backtrack(int depth, int& N, int& M, vector<int>& arr, vector<bool>& used)
{
    
    if (depth == M) {
        for (int num : arr)
        {
            cout << num << ' ';
        }            
        cout << '\n';
        return;
    }

    for(int i = 1; i <= N; i++)
    {
        if(used[i])
        {
            continue; 
        } 
        else
        {
            used[i] = true;
            arr.push_back (i);

            backtrack(depth + 1, N, M, arr, used);

            used[i] = false;
            arr.pop_back();
        }
    }
}
int main() {
    FAST_IO;
    int N, M; cin >> N >> M;
    vector<int> arr;
    vector<bool> used(N+1, false);

    backtrack(0, N, M, arr, used);
}