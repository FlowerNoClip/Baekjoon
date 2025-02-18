#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> extractDigits(int number) {
    std::vector<int> digits;

    while (number != 0) {
        int digit = number % 10;  // 가장 오른쪽 자릿수를 추출
        digits.push_back(digit);   // 벡터에 추가
        number /= 10;              // 추출한 자릿수를 제거
    }

    // 자릿수를 뒤집어 정방향으로 정렬
    std::reverse(digits.begin(), digits.end());

    return digits;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    int iSum = 0;
    int tempValue = 0;
    int minValue = 0;
    std::cin >> N;

    // 자릿수를 벡터에 저장
    vector<int> digits = extractDigits(N);

    // 자릿수를 확인하고 싶다면 출력하여 확인 가능
    for (int i = 0; i < N; i++) {
        iSum = N - i;
        digits = extractDigits(iSum);
        for (int j = 0; j < digits.size(); j++) {
            tempValue += digits[j];
        }
        if (iSum + tempValue == N) {
            minValue = iSum;
        }
        tempValue = 0;
        digits.clear();
    }

    cout << minValue;

}

