#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);

int a,b,c;
int main() {
    FAST_IO;
    int a, b, c;
    cin >> a >> b >> c;
    if (c % 2 == 1) a ^= b;
    cout << a << '\n';
    return 0;
}