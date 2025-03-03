#include <iostream>
#include <ctime>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int l, r;
        l = 0;
        r = 0;
        cin >> l >> r;
        cout << l + r << endl;
    }
    
}
