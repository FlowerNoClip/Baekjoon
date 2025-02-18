#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 최대 직사각형 영역을 구하는 함수
long long maxhistogram(vector<int>& S, int left, int right) {
    // 한 막대만 있을 경우 그 자체가 최대 면적
    if (left == right) {
        return S[left];
    }

    int mid = (left + right) / 2;

    // 중간에서 확장하는 방법을 사용하기 전에, 왼쪽과 오른쪽 최대 직사각형 면적을 구합니다.
    long long leftArea = maxhistogram(S, left, mid);
    long long rightArea = maxhistogram(S, mid + 1, right);

    // 중간에서 양쪽으로 확장하여 최대 면적을 구합니다.
    long long maxArea = max(leftArea, rightArea);

    // 양쪽 끝에서 확장하면서 최소 높이를 유지하면서 면적을 계산합니다.
    int l = mid, r = mid + 1;
    int minHeight = min(S[l], S[r]);
    maxArea = max(maxArea, (long long)minHeight * 2);  // 초기 두 막대의 면적

    // 양쪽 끝을 확장하여 계산
    while (l > left || r < right) {
        if (r < right && (l == left || S[l - 1] < S[r + 1])) {
            r++;
            minHeight = min(minHeight, S[r]);
        }
        else {
            l--;
            minHeight = min(minHeight, S[l]);
        }
        maxArea = max(maxArea, (long long)minHeight * (r - l + 1));
    }

    return maxArea;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    while (1) {
        cin >> N;
        if (N == 0) break;

        vector<int> S(N);
        for (int i = 0; i < N; i++) {
            cin >> S[i];
        }

        cout << maxhistogram(S, 0, N - 1) << endl;
    }

    return 0;
}
