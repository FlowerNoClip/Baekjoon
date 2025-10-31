#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int main()
{
    int line = 1;
    int n; cin >>n;
    while(n - line > 0)
    {
        n-=line;
        line++;
    }

    if(line % 2) cout << line + 1 -n<<  '/' << n;
    else cout << n << '/' << line + 1 -n;
    return 0;

}