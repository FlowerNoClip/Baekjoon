#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool isPrime(int n)
{
    if (n < 2) return false; 
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

int main()
{
    FAST_IO;
    int m, n;
    cin >> m >> n;

    vector<int> v;
    for (int i = m; i <= n; i++) 
    {
        if (isPrime(i)) v.push_back(i);
    }

    if (v.empty())
    {
        cout << -1;
        return 0;
    }

    int sum = accumulate(v.begin(), v.end(), 0);
    cout << sum << '\n' << v[0] << '\n';
    return 0;
}
