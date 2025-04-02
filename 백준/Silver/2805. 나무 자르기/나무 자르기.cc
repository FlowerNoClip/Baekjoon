#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int low = 0; 
    int high = arr[N - 1]; 
    int result = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        long long ans = 0; 

        for (int i = 0; i < N; i++) {
            ans += max(0, arr[i] - mid); 
        }

        if (ans >= M) { 
            result = mid; 
            low = mid + 1; 
        }
        else { 
            high = mid - 1; 
        }
    }

    cout << result << endl; 
    return 0;
}