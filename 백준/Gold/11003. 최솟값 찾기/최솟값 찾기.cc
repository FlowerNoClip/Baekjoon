#include <iostream>  // 입출력 사용을 위해 필요
#include <vector>    // 벡터 자료구조 사용을 위해 필요
#include <deque>     // 덱 자료구조 사용을 위해 필요

using namespace std; // 표준 라이브러리의 네임스페이스 사용
typedef pair<int, int> Node; // (값, 인덱스) 형태의 쌍을 Node로 정의

int main() {
    ios::sync_with_stdio(false); // C와 C++ 표준 스트림의 동기화를 비활성화하여 입출력 속도를 높임
    cin.tie(0); // cin과 cout의 묶음을 해제하여 입력 속도를 높임
    cout.tie(0); // cout의 묶음을 해제하여 출력 속도를 높임

    int N, L; // N은 숫자의 개수, L은 슬라이딩 윈도우의 크기
    cin >> N >> L; // N과 L을 입력받음
    deque<Node> mydeque; // 덱을 사용하여 윈도우 내의 최소값을 관리

    for (int i = 0; i < N; i++) {
        int now; // 현재 입력 숫자를 저장할 변수
        cin >> now; // 숫자를 입력받음

        // 덱의 뒤에서부터 현재 숫자보다 큰 모든 요소를 제거
        while (!mydeque.empty() && mydeque.back().first > now) {
            mydeque.pop_back();
        }

        // 현재 숫자와 그 인덱스를 덱의 뒤에 추가
        mydeque.push_back(Node(now, i));

        // 덱의 앞쪽에 있는 요소가 윈도우 범위를 벗어나면 제거
        if (mydeque.front().second <= i - L) {
            mydeque.pop_front();
        }

        // 현재 윈도우에서의 최소값을 출력
        cout << mydeque.front().first << " ";
    }
}
