#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

int main()
{
    FAST_IO
     int N; cin >> N;
    while (N--) 
    {
        int temp; cin >> temp;
        int answer = 0;
        for (long long d = 5; d <= temp; d *= 5) {
            answer += temp / d;
        }
        cout << answer << '\n';
    }

}