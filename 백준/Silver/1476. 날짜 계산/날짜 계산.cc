#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int Ei = 1, Si = 1, Mi = 1;
    int E, S, M;
    cin >> E >> S >> M;

    int sum = 1; 

    while (true) {
        if (Ei == E && Si == S && Mi == M) {
            break;
        }

        Ei += 1;
        Si += 1;
        Mi += 1;

        if (Ei > 15) Ei = 1;
        if (Si > 28) Si = 1;
        if (Mi > 19) Mi = 1;

        sum += 1;
    }

    cout << sum;
}
