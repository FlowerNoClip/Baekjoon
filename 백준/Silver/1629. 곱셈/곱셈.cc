#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

ll divide(ll a, ll b, ll c) {
    if (b == 0) return 1 % c;
    if (b == 1) return a % c;

    ll temp = divide(a, b/2, c);
    temp = (temp * temp) % c;

    if (b % 2 == 1) temp = (temp * a) % c;
    return temp;
}
int main()
{
    //A * B / C = ((A%C) * (B % C)) % C
    FAST_IO
    int A, B, C;
    cin >> A >> B >> C;
    cout << divide(A, B, C) << '\n';

}