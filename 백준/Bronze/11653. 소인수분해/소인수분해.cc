#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    FAST_IO;
    long long n;
    cin >> n;

    vector<int> factors;

    for (long long i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) factors.push_back(n);

    for (int x : factors)
    {
        cout << x << "\n";
    }        
}