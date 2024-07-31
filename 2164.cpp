#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false); // C++ 표준 입출력의 속도 향상을 위해 사용
	cin.tie(0);                  // 입출력의 동기화를 끊음
	cout.tie(0);                 // 출력 스트림의 묶음을 끊음

	queue<int> myQueue;          // 정수를 저장할 큐 선언
	int N;                       // 숫자의 개수
	cin >> N;                    // 숫자 개수 입력

	// 1부터 N까지의 숫자를 큐에 추가
	for (int i = 1; i <= N; i++) {
		myQueue.push(i);
	}

	// 큐의 크기가 1보다 클 동안 반복
	while (myQueue.size() > 1) {
		myQueue.pop();                  // 첫 번째 숫자를 버림
		myQueue.push(myQueue.front());  // 두 번째 숫자를 맨 뒤로 이동
		myQueue.pop();                  // 이동한 숫자를 다시 버림
	}

	cout << myQueue.front();  // 큐에 남아 있는 마지막 숫자를 출력
}
