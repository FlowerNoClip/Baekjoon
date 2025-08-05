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
const ll LLINF = 2e9 + 1;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;
    int startIndex = -1;

    for(int i = 0; i < 13; i++)
    {
        if(str[i] == '*')
        {
            startIndex = i;
            break;
        }
    }

    for(int digit = 0; digit <= 9; digit++)
    {
        int sum = 0;
        for(int i = 0; i < 13; i++)
        {
            int val;
            if(i == startIndex)
            {
                val = digit;
            }
            else
            {
                val = str[i] - '0';
            }

            if(i%2 == 0)
            {
                sum += val;
            }
            else
            {
                sum += val * 3;
            }
        }
        if((sum%10) == 0)
        {
            cout << digit;
            break;
        }
    }
}