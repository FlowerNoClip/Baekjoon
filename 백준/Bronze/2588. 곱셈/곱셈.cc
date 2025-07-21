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

int N,M;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<long long> answer;
    int r = 1;
    cin >> N >> M;
    while(M)
    {
        int temp = ((M%10) * N) * r;
        
        answer.push_back(temp);
        M /= 10;
    }
    long long result = 0;
    for(long long i : answer)
    {
        cout << i << "\n";
        result += i * r;
        r *= 10;
    }
    cout << result;
}
