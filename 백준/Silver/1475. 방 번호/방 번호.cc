#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int a[10];

int main()
{
    FAST_IO
    string s; cin >> s;

    for(char c : s)
    {
        a[c - '0']++;
    }

    int sixNine = a[6] + a[9];
    a[6] = a[9] = (sixNine + 1) / 2;

    int maxNum = 0;
    for(int i = 0; i < 10; i++)
    {
        maxNum = max(maxNum, a[i]);
    }

    cout << maxNum;
}