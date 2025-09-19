#include <iostream>
using namespace std;

// 666이 포함된지 확인하는 함수
bool containsThreeConsecutiveSix(int number) {
    // 연속된 6의 개수를 세는 변수
    int count = 0;
    while (number > 0) {
        // 현재 자릿수가 6이면 count 증가
        if (number % 10 == 6) {
            count++;
            // 6이 3개 이상이면 true 반환
            if (count >= 3) {
                return true;
            }
        }
        else {
            count = 0; // 6이 아니면 count 초기화
        }
        number /= 10; // 다음 자릿수로 이동
    }
    return false; // 연속된 6이 없으면 false 반환
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    int movieNumber = 666; // 시작하는 영화 번호
    int count = 0; // 666이 포함된 영화 번호의 수

    // N번째 영화 번호를 찾기 위한 반복문
    while (count < N) {
        if (containsThreeConsecutiveSix(movieNumber)) {
            count++;
        }
        movieNumber++; // 다음 영화 번호로 이동
    }

    cout << movieNumber - 1 << endl; // 결과 출력 (마지막으로 증가시킨 값을 빼줍니다)
    return 0;
}
