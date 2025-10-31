#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n = 0, x;
    string s;

    cin >> m;
    while (m--) {
        cin >> s;
        if (s == "add") {
            cin >> x;
            n |= (1 << x);
        }
        else if (s == "remove") {
            cin >> x;
            n &= ~(1 << x);
        }
        else if (s == "check") {
            cin >> x;
            cout << ((n & (1 << x)) ? 1 : 0) << '\n';
        }
        else if (s == "toggle") {
            cin >> x;
            n ^= (1 << x);
        }
        else if (s == "all") {
            n = (1 << 21) - 1;
        }
        else if (s == "empty") {
            n = 0;
        }
    }
    return 0;
}
