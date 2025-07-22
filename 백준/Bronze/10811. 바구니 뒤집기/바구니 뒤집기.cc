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
    vector<int> basket;
    for(int i = 1; i <= N; i++)
    {
        basket.push_back(i);
    }
    while(M--)
    {
        cin >> X >> Y;
        if(X!=Y)
        {
            reverse(basket.begin() + X-1, basket.begin() + Y);
        } 
    }

    for(int num : basket)
    {
        cout << num << " ";
    }
}