#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int res = 0;
    vector<double> arr(N);

    if (N == 0)
    {
        cout << res;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int size = round(N * 0.15);
    double answer = 0;

    for (int i = size; i < N - size; i++)
    {
        answer += arr[i];
    }

    
    res = round(answer / (N - size * 2));

    cout << res;

    return 0;
}
