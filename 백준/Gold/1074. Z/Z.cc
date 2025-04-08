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
int answer = 0;
int r, c;
void divide(int x, int y, int size) {
    if (c == x && y == r)
    {
        cout << answer;
        return;
    }
    else if (c < x + size && r < y + size && c >= x && r >= y)
    {
        divide(x, y, size / 2);
        divide(x + size / 2, y, size / 2);
        divide(x, y + size / 2, size / 2);
        divide(x + size / 2, y + size / 2, size / 2);
    }
    else
    {
        answer += size * size;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N >> r >> c;
    divide(0, 0, pow(2, N));

    
}
