#include <iostream>
#include <unordered_map>
#include <queue>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;




int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M; cin >> N >> M;
    int num;
    vector<int> arr(N+1,0);
    for (int i = 1; i <= N; i++)
    {
        cin >> num;
        arr[i] = arr[i - 1] + num;
    }

    while (M--)
    {
        int x, y;
        cin >> x >> y;

        cout << arr[y] - arr[x - 1] << "\n";
    }
}