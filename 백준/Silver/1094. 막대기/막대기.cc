#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int n = 64, x, cnt = 0;

int main()
{
    cin >> x;
    for(int i = 0; i < 7; i++)
    {
        if(x & (1 << i))
        {
            cnt ++;
        }
    }

    cout <<cnt << endl;
}