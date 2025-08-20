#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 

int main()
{
    FAST_IO;
    string str, temp;
    
    cin >> str;
    temp = str;
    reverse(temp.begin(), temp.end());
    if(temp == str)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }

}