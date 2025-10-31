#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    int B;
    cin >> N >> B;

    string result = "";
    while (N > 0) {
        int r = N % B; // 나머지
        if (r < 10) result += (r + '0');
        else result += (r - 10 + 'A');
        N /= B;
    }

    reverse(result.begin(), result.end());
    cout << result;
}