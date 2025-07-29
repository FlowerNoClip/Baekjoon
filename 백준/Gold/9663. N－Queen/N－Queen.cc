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

int N;
int cnt = 0;
vector<int> col_used;
bool isValid(int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        if(col_used[i] == col) return false;

        if(abs(row - i) == abs(col - col_used[i])) return false;

    }
    return true;
}

void backtracking(int row)
{
    if(row == N)
    {
        cnt++;
        return;
    }
    
    for(int col = 0; col < N; col++)
    {
        if(isValid(row, col))
        {
            col_used[row] = col;
            backtracking(row + 1);
        }
    }

}

int main() {
    FAST_IO;
    cin >> N;
    col_used.resize(N);
    backtracking(0);
    cout << cnt;
    
}