#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, r;
    cin >> n >> m >> r;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int layers = min(n, m) / 2;

    while (r--) {
        for (int layer = 0; layer < layers; layer++) {
            int top = layer;
            int left = layer;
            int bottom = n - layer - 1;
            int right = m - layer - 1;

            int prev = a[top][left];

            for (int i = top + 1; i <= bottom; i++)
                swap(a[i][left], prev);

            for (int j = left + 1; j <= right; j++)
                swap(a[bottom][j], prev);

            for (int i = bottom - 1; i >= top; i--)
                swap(a[i][right], prev);

            for (int j = right - 1; j >= left; j--)
                swap(a[top][j], prev);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << '\n';
    }
}
