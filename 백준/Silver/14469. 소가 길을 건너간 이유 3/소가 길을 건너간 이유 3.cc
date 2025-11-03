#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, aTime, iTime, leftNum, rightNum;
vector<pair<int, int>> v;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> aTime >> iTime; v.push_back({aTime, iTime});
    }

    sort(v.begin(), v.end());
    int realTime = v[0].first + v[0].second;
    for(int i = 1; i < v.size(); i++)
    {
        realTime = max(realTime, v[i].first);
        realTime += v[i].second;
    }

    cout << realTime << endl;
}