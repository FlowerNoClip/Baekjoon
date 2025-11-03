#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int n, k, value, price;
vector<pair<int, int>> ju;
priority_queue<int> pq;
long long result = 0;
vector<int> bag;
int main()
{
    FAST_IO
    cin >> n >> k;
    for(int i = 0; i < n; i ++)
    {
        cin >> value >> price;
        ju.push_back({value, price});
    }
    for(int i = 0; i < k; i++)
    {
        cin >> value;
        bag.push_back(value);
    }
    sort(ju.begin(), ju.end());
    sort(bag.begin(), bag.end()); 

    int j = 0;
    for(int i = 0; i < k; i++)
    {
        while(j < n && ju[j].first <= bag[i])
        {
            pq.push(ju[j].second);
            j++;
        }
        if(!pq.empty())
        {
            result += pq.top();
            pq.pop();
        }
    }
    cout << result;
}