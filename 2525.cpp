#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int A, B, C;
    cin >> A >> B >> C;

    B += C;
    A += B / 60;
    B %= 60;
    A %= 24;

    cout << A << " " << B << "\n";
    return 0;
}
