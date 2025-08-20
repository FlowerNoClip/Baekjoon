#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 

int main()
{
    FAST_IO;
    int N; cin >> N;
    string tempstr; cin >> tempstr;
    int pos = tempstr.find('*');
    string start = tempstr.substr(0, pos);
    string end = tempstr.substr(pos+1);

    while(N--)
    {
        string s; cin >> s;
        if(start.size() + end.size() > s.size())
        {
            cout << "NE" << '\n';
        }
        else
        {
            if(start == s.substr(0, start.size()) && end == s.substr(s.size() - end.size()))
            {
                cout << "DA" << '\n';
            }
            else
            {
                cout << "NE" << '\n';
            }
        }
    }


}