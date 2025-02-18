#include <iostream>
#include <vector>
#include <limits> // std::numeric_limits 사용
using namespace std;

int closestSum = 0; // M과 가장 가까운 합계

void generateCombinations(vector<int>& nums, vector<int>& combination, int start, int depth, int M) {
    if (depth == 0) { // 원하는 크기에 도달했을 때
        int sum = 0; // 합계를 저장할 변수
        for (int num : combination) {
            sum += num; // 각 숫자를 합계에 추가
        }

        // 합이 M을 넘지 않는 경우에만 업데이트
        if (sum <= M && sum > closestSum) {
            closestSum = sum; // 가장 가까운 합계 업데이트
        }
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        combination.push_back(nums[i]); // 현재 숫자를 조합에 추가
        generateCombinations(nums, combination, i + 1, depth - 1, M); // 다음 숫자 선택
        combination.pop_back(); // 조합에서 마지막 숫자를 제거
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> nums(N);
    vector<int> combination;

    for (int i = 0; i < nums.size(); i++) {
        cin >> nums[i]; // 카드 숫자 입력 받기
    }

    generateCombinations(nums, combination, 0, 3, M); // 3장의 카드 조합 생성

    cout << closestSum; // 가장 가까운 합계 출력
    return 0;
}
