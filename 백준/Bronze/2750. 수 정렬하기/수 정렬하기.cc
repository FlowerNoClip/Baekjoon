#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector <int> S(N, 0);

    for (int i = 0; i < S.size(); i++) {
        cin >> S[i];
    }
    sort(S.begin(), S.end());

    for (int i = 0; i < S.size(); i++) {
        cout << S[i] << endl;
    }
   


}

