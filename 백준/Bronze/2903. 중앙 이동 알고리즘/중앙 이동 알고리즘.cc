// n = 1로 시작
// n + 1 * n + 1 를 하면

// n 이 1일때  3 * 3 = 9 n * 2 - 1 이라면 ? 
// n 이 2일때 5 * 5 = 25
// n 이 3일때 9 * 9 = 91
// n 이 4일때 17 * 17 = 289
// n 이 5일때 33 * 33 = 1089
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int n;
int main()
{
    long long arr[16];
    arr[0] = 1;
    arr[1] = 3;
    arr[2] = 5;

    int n;
    cin >> n;

    for (int i = 3; i <= n; i++)
    {
        arr[i] = arr[i - 1] * 2 - 1;
    }
    cout << arr[n] * arr[n]; 
}