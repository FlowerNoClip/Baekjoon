#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    FAST_IO;
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        string s;
        cin >> s;
        int len = s.size();
        int answer = 0;
        
        // 마디는 최대 10글자
        for (int m = 1; m <= 10; ++m) {
            string pattern = s.substr(0, m);
            bool ok = true;
            for (int i = 0; i < len; i++) {
                if (s[i] != pattern[i % m]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                answer = m;
                break;
            }
        }
        cout << "#" << tc << " " << answer << "\n";
    }
}
