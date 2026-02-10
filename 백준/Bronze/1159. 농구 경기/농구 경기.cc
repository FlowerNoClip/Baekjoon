#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    // 1. 입력을 받을때 첫글자를 카운팅 배열로 카운팅 한다
    // 2. 나중에 카운팅 배열에서 5이상인 경우가 나오면 정답 배열에 넣어둔다
    // 3. 만약 result.size() 가 null 이면 PREDAJA 를 출력한다

    int N; cin >> N;
    vector<char> a;
    int cnt[26] = {0};
    for(int i = 0; i < N; i++)
    {
        string temp; cin >> temp;
        cnt[temp[0] - 'a']++;       
    }
    for(int i = 0; i < 26; i++)
    {
        if(cnt[i] >= 5)
        {
            a.push_back(i + 'a');
        }
    }
    //sort(a.begin(), a.end());
    if(!a.size())
    {
        cout << "PREDAJA";
    }
    else
    {
        for(auto i: a)
        {
            cout << i;
        }
    }
    
}