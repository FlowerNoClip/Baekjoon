#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        long long result = 1;
        int N = 0;
        int M = 0;
        
        cin >> N >> M;
        
        int temp = 1;
        for(int j = M; j >= M - N + 1; j--) {
            result = result * j;
            result = result / temp;
            temp++;
        }

        cout << result << endl;
    }
    return 0;
}
