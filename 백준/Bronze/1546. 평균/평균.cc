#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    vector<int> nums;
    int temp;

    while (T--) {
        cin >> temp;
        nums.push_back(temp);
    }

    sort(nums.begin(), nums.end());

    int max_Num = *max_element(nums.begin(), nums.end()); // 가장 큰 값 찾기
    double average = 0.0;

    for (int i = 0; i < nums.size(); i++) {
        average += static_cast<double>(nums[i]) / max_Num; // 정수 나눗셈 방지
    }

    average /= nums.size(); // 평균 계산

    cout << fixed;
    cout.precision(6); // 소수점 이하 6자리까지 출력
    cout << average * 100 << endl;

    return 0;
}
