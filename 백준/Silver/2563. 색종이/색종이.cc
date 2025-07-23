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
int board[101][101] = {0};
int main() {
    FAST_IO;
    int N; cin >> N;
    int X, Y;
    while(N--)
    {
        cin >> X >> Y;
        for(int i = X; i < X+10; i++)
        {
            for(int j = Y; j < Y+10; j++)
            {
                if(board[i][j] == 0)
                {
                    board[i][j] = 1;
                }
                
            }
        }
    }
    int result = 0;
    for(int i = 0; i < 100; i++)
        {
            for(int j = 0; j < 100; j++)
            {
                if(board[i][j] == 1)
                {
                    result += 1;
                }
            }
        }
    cout << result;
}