#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    int x, y, h, w;
    cin >> x >> y >> w >> h;

    int ans = min(min(abs(w - x), abs(h - y )), min(x, y));
    cout << ans;
}