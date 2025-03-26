#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;

    while (N--) {
        unordered_map<string, int> map; // 각 반복마다 초기화
        int answer = 1; // 초기값 설정
        cin >> M;
        for (int i = 0; i < M; i++) {
            string item, category;
            cin >> item >> category;
            map[category]++;
        }


        for (auto& pair : map) {
            string key = pair.first;
            int value = pair.second;
            answer *= (value + 1);
        }


        cout << answer - 1 << '\n'; // 모든 경우의 수 계산 후, 1을 빼줌 (아무것도 선택하지 않는 경우 제외)
    }

    return 0;
}