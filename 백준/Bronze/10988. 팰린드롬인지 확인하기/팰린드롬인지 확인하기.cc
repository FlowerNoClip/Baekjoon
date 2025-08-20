#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 

int main()
{
    FAST_IO;
    string str; cin >> str;

    for(int i = 0; i < str.length()/2; i++)
    {
        if(str[i] != str[str.length() - i - 1])
        {
            cout << 0;
            return 0;
        }
    }

    cout << 1;
}