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
    FAST_IO;
    int N; cin >> N;
    vector<int> number(N);
    for(int& num : number) cin >> num;
    int X; cin >> X;

    sort(number.begin(), number.end());

    int left = 0; int right = N-1; int cnt = 0; int temp = 0;
    while(left < right)
    {
        
        temp = number[left] + number[right];
        if(temp == X)
        {
            cnt++;
            right--;
            
        }
        else if(temp >= X)
        {
            right--;
        }
        else
        {
            left++;
        }
        temp = 0;
    }

    cout << cnt;
}