#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int a,b;
int main()
{
    while(true)
    {
        cin >> a >> b;
        if(a == 0 && b == 0) break;
        if(b %  a== 0)
        {
            cout << "factor" << endl;
        }
        else if(a % b == 0)
        {
            cout << "multiple" << endl;
        }
        else
        {
            cout << "neither" << endl;
        }
    }

}