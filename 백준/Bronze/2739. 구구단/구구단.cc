#include <iostream>
#include <ctime>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;

    for (int i = 1; i <= 9; i++)
    {
        cout << N << " * " << i << " = " << N * i << endl;
    }
    
}
