#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#include <unordered_map>
using namespace std;
vector<pair<int,int>> v;
map<int, int> mp, mp_first;
int a[1004];
bool cmp(pair<int,int> a, pair<int, int> b)
{
    if(a.first == b.first)
    {
        return mp_first[a.second] < mp_first[b.second];
    }

    return a.first > b.first;
}
int main()
{
    FAST_IO
    int N, M; cin >> N >> M;
    
    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
        mp[a[i]] ++;
        if(mp_first[a[i]] == 0) mp_first[a[i]] = i + 1;
    }

    for(auto it : mp)
    {
        v.push_back({it.second, it.first});
    }
    sort(v.begin(), v.end(), cmp);
    for(auto i : v)
    {
        for(int j = 0; j < i.first; j++)
        {
            cout << i.second << " ";
        }
    }

}