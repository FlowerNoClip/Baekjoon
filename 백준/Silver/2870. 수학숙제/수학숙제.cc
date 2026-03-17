#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    int N; cin >> N;
    vector<string> ret;
    while(N--)
    {
        string temp; cin >> temp;
        string str = "";
        for(char c : temp)
        {
            if(isdigit(c))
            {
                str += c;
            }
            else
            {
                if(!str.empty())
                {
                    while(str.size() > 1 && str[0] == '0')
                    {
                        str.erase(0, 1);
                    }
                    ret.push_back(str);
                    str = "";
                }
            }
            
        }
        if(!str.empty())
        {
            while(str.size() > 1 && str[0] == '0')
            {
                str.erase(0, 1);
            }
            ret.push_back(str);
            str = "";
        }
    }
    sort(ret.begin(), ret.end(), [](const string &a, const string &b)
    {
        if(a.size() != b.size()) return a.size() < b.size();
        return a < b;
    });

    for(const string &a : ret)
    {
        cout << a << '\n';
    }
}