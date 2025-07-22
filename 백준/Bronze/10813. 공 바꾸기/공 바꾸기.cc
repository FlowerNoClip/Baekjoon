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
    int N, M, X, Y;
    cin >> N >> M;
    vector<int> basket(N);
    for(int i = 0 ; i < N; i++)
    {
        basket[i] = i+1;
    }
    
    while(M--)
    {        
        cin >> X >> Y; 
        if((basket[X] != basket[Y]) || (X != Y))
        {
            swap(basket[X - 1], basket[Y - 1]);
        }
    }

    for(int num : basket)
    {
        cout << num << " ";
    }
}