#include <iostream>
#include <ctime>

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    int sol = 1;
    for (int i = N; i >= 1; --i)
    {
        sol *= i;
    }

    cout << sol;
    
}
