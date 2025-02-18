#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int sum = 0;
    int L, P, V;
    int su = 0;
    
    while (true) {
        cin >> L >> P >> V;
        if (L == 0 || P == 0 || V == 0) {
            break;
        }
        sum = 0;

        while (V > 0) {
            if (V < P) {
                if (V < L) {
                    sum += V; // 남은 날이 L보다 작으면 V를 더함
                }
                else {
                    sum += L; // 남은 날이 L보다 크거나 같으면 L을 더함
                }
                break;
            }
            else {
                V -= P;
                sum += L;
            }
        }
        su++;
        cout << "Case " << su << ": " << sum << endl;
        
        
    }

}

