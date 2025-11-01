#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n;
int main()
{
    FAST_IO;
    while (1)
    {
        cin >> n;
        if (n == -1) break;

        vector<int> v;
        for (int i = 1; i <= n / 2; i++)
        {
            if (n % i == 0) v.push_back(i);
        }

        int tempnum = accumulate(v.begin(), v.end(), 0);

        if (tempnum != n)
        {
            cout << n << " is NOT perfect.\n";
            continue;
        }

        cout << n << " = ";
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];
            if (i != v.size() - 1) cout << " + ";
        }
        cout << '\n';
    }
    return 0;
}
