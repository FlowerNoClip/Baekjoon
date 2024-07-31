#include <iostream>
#include <queue>

using namespace std;

// 사용자 정의 비교 구조체
struct compare {
	// 비교 연산자 오버로딩
	bool operator()(int o1, int o2) {
		int first_abs = abs(o1);   // 첫 번째 수의 절댓값
		int second_abs = abs(o2);  // 두 번째 수의 절댓값
		if (first_abs == second_abs) {
			return o1 > o2;        // 절댓값이 같으면 원래의 값으로 비교
		}
		else {
			return first_abs > second_abs; // 절댓값이 작은 순으로 우선순위 결정
		}
	}
};

int main() {
	ios::sync_with_stdio(false); // 표준 입출력 속도 향상을 위한 설정
	cin.tie(0);                  // 입력과 출력의 묶음을 끊음
	cout.tie(0);                 // 출력 스트림의 묶음을 끊음

	priority_queue<int, vector<int>, compare > MyQueue; // 사용자 정의 비교를 사용한 우선순위 큐 선언

	int N;                       // 명령의 개수
	cin >> N;

	for (int i = 0; i < N; i++) {
		int request;
		cin >> request;

		if (request == 0) {
			// 큐가 비어 있을 때
			if (MyQueue.empty()) {
				cout << "0" << endl; // 0 출력
			}
			else {
				cout << MyQueue.top() << endl; // 가장 우선순위가 높은 값 출력
				MyQueue.pop();                 // 출력 후 큐에서 제거
			}
		}
		else {
			MyQueue.push(request); // 0이 아닌 경우, 우선순위 큐에 값을 추가
		}
	}
}
