#include <iostream>
#include <vector>

using namespace std;

struct wh {
    int w;
    int h;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<wh> S(N);
    vector<int> rank(N, 1);

    for (int i = 0; i < S.size(); i++) {
        cin >> S[i].w >> S[i].h;
    }

    for (int i = 0; i < S.size(); i++) {
        for (int j = 0; j < S.size(); j++) {
            if (i != j && S[i].w < S[j].w && S[i].h < S[j].h) {
                rank[i] += 1;
            }
        }
    }

    for (int i = 0; i < rank.size(); i++) {
        cout << rank[i] << " ";
    }

    return 0;
}
