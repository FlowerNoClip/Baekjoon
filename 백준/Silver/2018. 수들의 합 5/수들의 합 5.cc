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

int main() {
    int N;
    cin >> N;

    int l = 1; 
    int r = 1;
    int sum = 1;
    int cnt = 1;

    while(r != N)
    {
        if(sum == N)
        {
            cnt++;
            r++;            
            sum+=r;
        }
        else if(sum > N)
        {            
            sum -= l;
            l++;
        }
        else
        {
            r++;
            sum += r;
        }
    }
    cout << cnt;
}