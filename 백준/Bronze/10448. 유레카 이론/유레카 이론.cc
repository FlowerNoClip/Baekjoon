#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool sol(vector <int>& s, int n) {
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s.size(); j++) {
            for (int k = 0; k < s.size(); k++) {
                if (s[i] + s[j] + s[k] == n) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector <int> a(N);
    vector <int> s;

    for (int i = 1; i < 45; i++) {
        s.push_back(i * (i + 1) / 2);
    }

    for (int i = 0; i < a.size(); i++) {
        cin >> a[i];
    }

    for (int i = 0; i < a.size(); i++) {
        cout << sol(s, a[i]) << endl;
    }


    

    }



