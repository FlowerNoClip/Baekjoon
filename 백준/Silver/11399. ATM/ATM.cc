#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector <int> P(N+1);
    vector <int> PP(N+1);

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    sort(P.begin(), P.end());

    for (int i = 1; i < P.size(); i++) {
        PP[i] = PP[i - 1] + P[i];
    }
    int sum = 0;
    for (int i = 1; i < PP.size(); i++) {
        sum+= PP[i];
    }

    cout << sum;

}
