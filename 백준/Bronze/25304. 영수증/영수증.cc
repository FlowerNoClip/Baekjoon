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
long long X , N;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> X >> N;

    while(N--)
    {
        long long tempx, tempy;
        cin >> tempx >> tempy;
        X -= tempx * tempy;
    }

    if(X == 0)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}
