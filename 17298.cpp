#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false); // C++ 입출력 속도를 높이기 위한 설정
	cin.tie(0);                  // 입출력의 동기화를 끊음
	cout.tie(0);                 // 출력 스트림의 묶음을 끊음

	int N;                       // 배열의 크기
	cin >> N;
	vector<int> A(N, 0);         // 입력된 숫자를 저장할 벡터
	vector<int> ans(N, 0);       // 결과를 저장할 벡터

	for (int i = 0; i < N; i++) {
		cin >> A[i];              // 숫자 입력 받기
	}

	stack<int> myStack;          // 스택을 사용해 인덱스를 저장
	myStack.push(0);             // 스택에 첫 번째 인덱스 추가

	for (int i = 1; i < N; i++) {
		// 스택이 비어있지 않고, 현재 인덱스의 값이 스택의 최상위 값보다 클 때까지 반복
		while (!myStack.empty() && A[myStack.top()] < A[i]) {
			ans[myStack.top()] = A[i]; // 다음 큰 수를 현재 위치에 기록
			myStack.pop();             // 스택에서 최상위 인덱스를 제거
		}
		myStack.push(i);               // 현재 인덱스를 스택에 추가
	}

	// 스택에 남아있는 인덱스의 경우, 다음 큰 수가 없으므로 -1로 설정
	while (!myStack.empty()) {
		ans[myStack.top()] = -1;
		myStack.pop();
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";        // 결과를 출력
	}
}
