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
int N,X,Y;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //Case #1: 2
    cin >> N;
    vector<int> answer;
    while(N--)
    {
        cin >> X >> Y;
        answer.push_back(X + Y);
    }
    for(int i = 0; i < answer.size(); i++)
    {
        cout << "Case #" << i+1  << ": " << answer[i] << "\n" ;
    }
}
