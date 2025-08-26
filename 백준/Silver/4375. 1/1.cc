#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        int rem = 0; 
        int len = 0;


        while (true) {
            rem = (rem * 10 + 1) % n; 
            ++len;
            if (rem == 0) {           
                cout << len << '\n';
                break;
            }
        }
    }
    return 0;
}
