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
    int a, b;
    cin >> a >> b;
    string tempa, tempb;
    while(a)
    {
        tempa += (a%10) + '0';
        a /= 10;
    }

    while(b)
    {
        tempb += (b%10) + '0';
        b /= 10;
    }
    
    cout << max(stoi(tempa),stoi(tempb)) ;
}