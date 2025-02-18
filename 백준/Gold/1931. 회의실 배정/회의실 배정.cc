#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct meet {
    int st;
    int ed;
    bool operator< (meet& m) {
        if (ed != m.ed) { return ed < m.ed; }
        return st < m.st;        
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector <meet> S(N);

    for (int i = 0; i < N; i++) {
        cin >> S[i].st >> S[i].ed;
    }

    sort(S.begin(), S.end());
    int temp = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        
        if (S[i].st < temp) continue;
        temp = S[i].ed;
        ans++;
    }
    cout << ans;
}
