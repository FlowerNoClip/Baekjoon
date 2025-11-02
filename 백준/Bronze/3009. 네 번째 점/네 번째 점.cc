#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    FAST_IO
    int x[3], y[3];
    for(int i = 0; i < 3; i++)
    {
        cin >> x[i] >> y[i];
    }

    int rx, ry;
    if(x[0] == x[1]) rx = x[2];
    else if(x[0] == x[2]) rx = x[1];
    else rx = x[0];

    if(y[0] == y[1]) ry = y[2];
    else if(y[0] == y[2]) ry = y[1];
    else ry = y[0];

    cout << rx << " " << ry ;
}