#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 

int main()
{
    FAST_IO;
    int N, M; cin >> N >> M;
    vector<int> v(N);
    for(int& a : v)
    {
        cin >> a;
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    int left = 0, right = N-1;
    while(left < right)
    {
        int sum = v[left] + v[right];
        if(sum == M)
        {
            cnt++;
            right--;
            left++;
        }
        else if(sum > M)
        {
            right--;
        }
        else
        {
            left++;
        }
    }

    cout << cnt;
}