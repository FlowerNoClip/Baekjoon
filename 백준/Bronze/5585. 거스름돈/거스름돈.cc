#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    N = 1000-N;
    int sum = 0;
    while (true){
        if (N == 0) {
            break;
        }
        if (N >= 500) {
            N = N - 500;
            sum += 1;
        }
        else if (N >= 100) {
            N = N - 100;
            sum += 1;
        }
        else if (N >= 50) {
            N = N - 50;
            sum += 1;
        }
        else if (N >= 10) {
            N = N - 10;
            sum += 1;
        }
        else if (N >= 5) {
            N = N - 5;
            sum += 1;
        }
        else if (N >= 1) {
            N = N - 1;
            sum += 1;
        }
    }
    cout << sum;
 

}
