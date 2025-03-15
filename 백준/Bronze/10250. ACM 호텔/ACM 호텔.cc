#include <iostream>
using namespace std;

int main() {
    int T; // 테스트 케이스 개수
    cin >> T;
    
    while (T--) {
        int H, W, N; // 층 수, 방 수, N번째 손님
        cin >> H >> W >> N;
        
        // 방 번호 계산
        int floor = (N - 1) % H + 1;  // N번째 손님의 층 번호
        int room = (N - 1) / H + 1;  // N번째 손님의 방 번호
        cout << floor * 100 + room << endl; // 방 번호 출력
    }
    
    return 0;
}
