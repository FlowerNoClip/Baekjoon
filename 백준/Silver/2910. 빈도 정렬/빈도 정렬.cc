#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FAST_IO
    int N, M;
    cin >> N >> M;
    vector<int> v;
    map<int, int> cMap;
    map<int, int> dMap;
    int idx = 0;
    for(int i= 0; i < N; i++)
    {
        int a; cin >> a;
        v.push_back(a);
        cMap[a]++;
        if(dMap.count(a) == 0)
        {
            dMap[a] = idx++;
        }
    }
    vector<pair<int, int>> vec(cMap.begin(), cMap.end());
    sort(vec.begin(), vec.end(), [&](const auto &a, const auto &b) 
    {
       if(a.second != b.second)
       {
        return a.second > b.second;
       }

       return dMap[a.first] < dMap[b.first];
    });
    for(auto i : vec)
    {
        for(int j = 0; j < i.second; j++)
        {
            cout << i.first << " " ;
        }
    }
}