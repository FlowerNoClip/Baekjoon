#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
int main()
{
    FAST_IO
    int N,M,J; cin >> N >> M >> J;
    int answer = 0;
    int left = 1;
    int right = left + (M - 1); // 1 + (5-1) == 5 
    for(int i = 0; i < J; i++)
    {
        int apple; cin >> apple;
        
        if(apple >= left && apple <= right)
        {
            continue;   
        }
        else if(apple < left)
        {
            int move = left - apple;
            answer += move;
            left -= move;
            right -= move;
        }
        else if(apple > right)
        {
            int move = apple - right;
            answer += move;
            left += move;
            right += move;
        }
    }

    cout << answer << endl;
}