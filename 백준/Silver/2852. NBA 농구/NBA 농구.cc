#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int N, team, sT1, sT2, lT1, lT2;
int prevT;

string toStr(int t)
{
    int m = t/60, s = t%60;
    return (m < 10 ? "0" : "") + to_string(m) + ":" + (s < 10 ? "0" : "") + to_string(s);
}

int toSec(const string &t)
{
    return (t[0] - '0')*600 + (t[1]-'0') * 60 + (t[3] -'0')*10 + (t[4]-'0');
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        string t;
        cin >> team >> t;

        int curT = toSec(t);

        if(sT1 > sT2) lT1 += (curT - prevT);
        else if(sT1 < sT2) lT2 += (curT - prevT);

        if(team == 1) sT1++;
        else sT2++;

        prevT = curT;
    }

    int endT = 48 * 60;

    if(sT1 > sT2) lT1 += (endT - prevT);
    else if(sT2 > sT1) lT2 += (endT - prevT);

    cout << toStr(lT1) << '\n';
    cout << toStr(lT2) << '\n';
}