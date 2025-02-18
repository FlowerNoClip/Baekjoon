#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
struct jewelry {
    int M;
    int V;
    bool operator<(jewelry j) {
        if (V != j.V) return V > j.V; // 종료 시간이 다르면 종료 시간이 빠른 순으로 정렬
        return M < j.M;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long sum = 0;
    int N, K ;
    cin >> N >> K;
    vector <jewelry> J(N);
    multiset <int> bag;

    for (int i = 0; i < N; i++) {
        cin >> J[i].M >> J[i].V;
    }

    for (int i = 0; i < K; i++) {
        int c; cin >> c;
        bag.insert(c);
    }

    sort(J.begin(), J.end());
    
    for (int i = 0; i < N; i++) {
        auto it = bag.lower_bound(J[i].M);
        if (it == bag.end()) continue;

        sum += J[i].V;
        bag.erase(it);
    }
    

    cout << sum;

    

    }
