#include <iostream>
#include <ctime>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long x, y;
    cin >> x >> y;
    long long sol = x - y;

    if (sol < 0)
    {
        sol -= sol * 2;
    }

    cout << sol;

    
}
