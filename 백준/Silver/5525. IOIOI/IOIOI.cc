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
    
    int N, M; cin >> N >> M;

    string s;
    cin >> s;

    int answer = 0;

    for (int i = 0; i < M; i++)
    {
        int length = 0;

        if (s[i] == 'O')
        {
            continue;
        }
        else
        {
            while (s[i + 1] == 'O' && s[i + 2] == 'I')
            {
                length++;
                if (length == N)
                {
                    length--;
                    answer++;
                }

                i += 2;
            }
            length = 0;
        }
    }
    
    cout << answer; 
}
