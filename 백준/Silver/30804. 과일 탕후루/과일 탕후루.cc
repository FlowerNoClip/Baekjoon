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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int type = 0;
    int cnt[10] = { 0 };
    int answer = 0;
    queue<int> q;
    cin >> N;

    while (N--)
    {
        int temp;
        cin >> temp;

        q.push(temp);
        if (cnt[temp]++ == 0)
        {
            ++type;
        }

        while (type > 2)
        {
            temp = q.front();
            q.pop();
            if (--cnt[temp] == 0)
            {
                type--;
            }
        }
        answer = max(answer, static_cast<int>(q.size()));
    }
    cout << answer << endl;
    
}
