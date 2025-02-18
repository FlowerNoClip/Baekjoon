#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> distance(N - 1);
    vector<int> oilprice(N);

    // 거리 입력
    for (int i = 0; i < N - 1; i++) {
        cin >> distance[i];
    }

    // 기름 가격 입력
    for (int i = 0; i < N; i++) {
        cin >> oilprice[i];
    }

    long long sum = 0;
    long long minOilPrice = oilprice[0];  // 첫 번째 주유소 가격으로 초기화

    // 첫 번째 도로부터 마지막 도로까지 이동하면서 기름을 넣는 비용을 계산
    for (int i = 0; i < N - 1; i++) {
        sum += (long long) distance[i] * minOilPrice;  // 현재 구간의 거리만큼 최소 기름 가격으로 비용 추가

        // 기름 가격이 더 낮아지면 그 가격으로 갱신
        if (oilprice[i + 1] < minOilPrice) {
            minOilPrice = oilprice[i + 1];
        }
    }

    cout << sum << "\n";

    return 0;
}
