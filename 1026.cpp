#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int sol(vector<int> A, vector<int> B) {
    int sum = 0;
    for (int i = 0; i < A.size(); i++) {
        sum += A[i] * B[i];
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector <int>A(N);
    vector <int>B(N);
    int S;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
    S = sol(A, B);

    cout << S;
}
