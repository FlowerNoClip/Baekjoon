#include <bits/stdc++.h>
using namespace std;

int n;
int a[44];
int ret = INT_MAX;

void go(int here, int maskN) {
    if (here == n + 1) {
        int sum = 0;
        for (int bit = 0; bit < n; ++bit) {
            int colMask = 1 << bit;
            int cntT = 0;
            for (int r = 1; r <= n; ++r) {
                if (a[r] & colMask) cntT++;
            }
            sum += min(cntT, n - cntT);
        }
        ret = min(ret, sum);
        return;
    }

    go(here + 1, maskN);

    a[here] ^= maskN;
    go(here + 1, maskN);

    a[here] ^= maskN;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int maskN = (1 << n) - 1;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        int v = 0, bit = 0;
        for (char c : s) {
            if (c == 'T') v |= (1 << bit);
            bit++;
        }
        a[i] = v;
    }

    go(1, maskN);
    cout << ret << "\n";
    return 0;
}
