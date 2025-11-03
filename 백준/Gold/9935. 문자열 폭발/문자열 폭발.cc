#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

string s, target, result;

int main()
{
    FAST_IO
    cin >> s >> target;
    for(char c : s)
    {
        result += c;
        if(result.size() >= target.size() && result.substr(result.size() - target.size(), target.size()) == target)
        {
            result.erase(result.end() - target.size(), result.end());
        }   
    }
    if(result.size())
    {
        cout << result << endl;
    }
    else
    {
        cout << "FRULA" << endl;
    }

}