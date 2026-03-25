#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;
int N;
vector<int> number;
vector<char> opers;
string str;
long long maxNum = -2e18;
int cal(int a, int b, char op)
{
    if(op == '+') return a + b;
    if(op == '*') return a * b;
    if(op == '-') return a - b;
    return 0;
}
void solved(int idx, int cur)
{
    if(idx >= opers.size())
    {
        maxNum = max(maxNum, (long long)cur);
        return;
    }

    int res1 = cal(cur, number[idx + 1], opers[idx]);
    solved(idx + 1, res1);

    if(idx+1 < opers.size())
    {
        int bracket = cal(number[idx + 1], number[idx + 2], opers[idx+1]);
        int res2 = cal(cur, bracket, opers[idx]);
        solved(idx + 2, res2);
    }
}
int main()
{
    FAST_IO
    cin >> N;
    cin >> str;
    for(int i = 0; i < str.length(); i++)
    {
        if(i % 2 == 0)
        {
            number.push_back(str[i]-'0');
        }
        else
        {
            opers.push_back(str[i]);
        }
    }
    if(N == 1)
    {
        cout << number[0];
        return 0;
    }
    solved(0, number[0]);
    cout << maxNum;
    
}