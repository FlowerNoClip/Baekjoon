#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int sol(int k, vector<int> s) {
    int p = 0;
    sort(s.rbegin(), s.rend());

    for (int coin : s) {
        p += k / coin;
        k %= coin;
        
    }
    return p;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector <int> s(n, 0);

    for (int i = 0; i < s.size(); i++) {
        cin >> s[i];
    }

    cout << sol(k, s);


        

    }



