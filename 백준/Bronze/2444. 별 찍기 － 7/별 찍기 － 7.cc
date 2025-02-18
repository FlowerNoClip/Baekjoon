#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;



    for (int i = 0; i < (2 * N - 1); i++) {
        int space = abs(N - 1 - i);      // 공백 수 계산
        int stars = (2 * (N - space) - 1); // 별 수 계산

        for (int k = 0; k < space; k++) cout << " ";
        for (int j = 0; j < stars; j++) cout << "*";

        cout << endl;
    }


}
