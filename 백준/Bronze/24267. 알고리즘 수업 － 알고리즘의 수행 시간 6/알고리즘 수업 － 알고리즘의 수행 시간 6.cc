#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long N;
    cin >> N;


    cout << (N-2)*(N-1)*N/6 << endl << "3";
    
    return 0;
}
