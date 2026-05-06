#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
int binarySearch(vector<int> v, int target)
{
    int left = 0, right = v.size() -1;
    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(v[mid] == target)
        {
            return mid;
        }
        else if(v[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    FAST_IO
    int N, M;
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    cin >> M;
    while(M--)
    {
        int a; cin >> a;
        cout << binarySearch(v,a) << " ";
    }
}