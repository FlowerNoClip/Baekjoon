#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

long long mod_exp(long long A, long long B, long long C) {
    if (B == 0) return 1;
    long long half = mod_exp(A, B / 2, C);
    half = (half * half) % C;
    if (B % 2 == 1) {
        half = (half * A) % C;
    }

    return half;

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long A, B, C;
    cin >> A >> B >> C;

    cout << mod_exp(A, B, C);



}
