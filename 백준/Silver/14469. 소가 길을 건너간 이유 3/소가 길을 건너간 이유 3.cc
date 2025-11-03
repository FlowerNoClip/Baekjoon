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
    leftNum = v[0].first;
    rightNum = leftNum + v[0].second;
    //3
    for(int i = 1; i < n; i++)
    {
        if(rightNum > v[i].first)
        // 3 > 5 X / 10 > 
        {
            leftNum = rightNum;
            rightNum += v[i].second;
        }
        else
        {
            leftNum = v[i].first;
            // 5
            rightNum += v[i].second + v[i].first - rightNum;
            // 3 + 7 = 10
        }
    }
 // 1, 2
 // 5, 7
 // 8, 3
    cout << rightNum;
}