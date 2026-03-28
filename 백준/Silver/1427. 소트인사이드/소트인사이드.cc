#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    string s; cin >> s;
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    cout << s;
}