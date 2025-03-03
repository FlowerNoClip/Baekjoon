#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long A, B;
    cin >> A >> B;
    long long Sol;
    Sol = (A + B) * (A - B);
    cout << Sol;
}
