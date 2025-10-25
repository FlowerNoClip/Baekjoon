#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string a[5];
    for (int i = 0; i < 5; i++) cin >> a[i];
    for (int j = 0; j < 15; j++)
        for (int i = 0; i < 5; i++)
            if (j < a[i].size()) cout << a[i][j];
}