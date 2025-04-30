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

int N, M;
int arr[10];
int num[10];
void seq(int x, int len)
{
    if (len == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << arr[i] << "\n";            
        }
        return;
    }
    int last = 0;

    for (int i = x; i < N; i++)
    {
        if (num[i] != last)
        {
            arr[len] = num[i];
            last = arr[len];
            seq(i, len + 1);
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    sort(num, num + N);
    seq(0, 0);
}
