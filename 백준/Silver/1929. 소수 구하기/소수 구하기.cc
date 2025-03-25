#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int target) {
    if (target < 2) return false; 
    for (int i = 2; i <= sqrt(target); i++) {
        if (target % i == 0) return false; 
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    bool first = true; 

    for (int i = N; i <= M; i++) {
        if (isPrime(i)) {
            if (first) {
                cout << i << "\n";
                first = false; 
            }
            else {
                cout << i << "\n";
            }
        }
    }

    return 0;
}
