#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    int T; cin >> T;
    int ans = 0;
    int ans2 = 0;
    int ans3 = 0;
    ans += T / 300;
    T %= 300;
    ans2 += T / 60;
    T %= 60;
    ans3 += T / 10;
    T %= 10;
    if(T != 0)
    {
        cout << -1 ; 
        return 0;
    }
    cout << ans << " " << ans2 << " " << ans3;
}