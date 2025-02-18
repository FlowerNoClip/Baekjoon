#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    if (N % 5 == 0) {
        cout << N / 5;
    }
    else {
        int p = 0;
        while (N > 0) {
            N -= 3;
            p += 1;
            if ( N % 5 == 0) {
                p += N / 5;
                cout << p;
                break;
            }
            else if (N == 1 || N == 2) {
                cout << "-1";
                break;
            }
            else if(N == 0) {
                cout << p;
            }
        }
    }

}

