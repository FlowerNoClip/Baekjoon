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
int N,S;
vector<int> arr;
int cnt = 0;
void func(int k, int sum)
{
    if(N==k)
    {
        if(sum == S)
        {
            cnt++;
        }
        return;
    }

    func(k+1, sum);
    func(k+1, sum + arr[k]);
}
int main() {
    FAST_IO;
    cin >> N >> S;
    arr.resize(N);
    for(int& n : arr) cin >> n;

    func(0,0);

    if(S==0) cnt--;

    cout << cnt;


}