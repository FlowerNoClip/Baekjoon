#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 

int main()
{
    FAST_IO;
    int N; cin >> N;
    string tempstr; cin >> tempstr;
    string perfix, suffix;
    bool flag = true;
    for(int i = 0; i < tempstr.length(); i++)
    {
        if(tempstr[i] == '*')
        {
            flag = false; 
            continue;
        }
        if(flag)
        {
            perfix += tempstr[i];
        }
        else if(!flag)
        {
            suffix += tempstr[i];
        }
    }

    while (N--) {
        string str; cin >> str;

        if (str.size() < perfix.size() + suffix.size()) {
            cout << "NE\n";
            continue;
        }

        bool per = (str.compare(0, perfix.size(), perfix) == 0);
        bool suf = (str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0);

        cout << ((per && suf) ? "DA\n" : "NE\n");
    }
}