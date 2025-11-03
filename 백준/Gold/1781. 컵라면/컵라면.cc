#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int n, value, day, result;

vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    FAST_IO
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> day >> value; v.push_back({day, value});

        // first = day, second = value
    }

    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++)
    {
        pq.push(v[i].second);
        {
            if(pq.size() > v[i].first)
            {
                pq.pop();
            }
        }
    }
    while(pq.size())
    {
        result += pq.top(); pq.pop();
    }
    cout << result;
}