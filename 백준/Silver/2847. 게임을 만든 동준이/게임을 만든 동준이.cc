#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    int n; cin >> n;
    vector<int> arr(n);
    for(int& i : arr) cin >> i;
    int ret = 0;


    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= arr[i + 1])
        {
            ret += (arr[i] - arr[i + 1] + 1);
            arr[i] = arr[i + 1] - 1;
        }
    }


    cout << ret << endl;
}