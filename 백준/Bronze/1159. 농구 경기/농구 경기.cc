#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 

int main()
{
    FAST_IO;
    int N; cin >> N;
    vector<char> v;
    vector<int> arr(27,0);
    string temp;
    vector<char> result;
    while(N--)
    {        
        cin >> temp;
        v.push_back(temp[0]);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
    {
        arr[(int)v[i] - 'a'] ++;
    }
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] >= 5)
        {
            result.push_back('a' + i);
        }
    }

    if(!result.empty()) 
    {
        for(char c : result)
        {
            cout << c;
        }
    }
    else
    {
        cout << "PREDAJA";
    }
}