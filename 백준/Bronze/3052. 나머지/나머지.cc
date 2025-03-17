#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    vector<int> N;
    int temp;

    for (int i = 0; i < 10; i++) {
        cin >> temp;
        int modValue = temp % 42;
        if (find(N.begin(), N.end(), modValue) == N.end()) {
            N.push_back(modValue); // 중복되지 않은 값만 추가
        }
    }

    cout << N.size() << endl; // 고유한 나머지 값의 개수 출력
    return 0;
}
