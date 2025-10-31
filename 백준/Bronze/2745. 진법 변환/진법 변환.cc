#include <bits/stdc++.h>
using namespace std;

int main() {
    string N;
    int B;
    cin >> N >> B;

    long long result = 0;
    long long power = 1; 

    for (int i = N.size() - 1; i >= 0; i--) {
        int val;
        if ('0' <= N[i] && N[i] <= '9') val = N[i] - '0';
        else val = N[i] - 'A' + 10;

        result += val * power;
        power *= B;
    }

    cout << result;
}
