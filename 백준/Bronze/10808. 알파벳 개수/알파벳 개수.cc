#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 

int main()
{
    FAST_IO;
    string str;
    cin >> str;
    int a[26] = {0};

    for(int c : str)
    {
        a[c-'a']++;
    }
    
    for(int i = 0; i < 26; i++)
    {
        cout << a[i] << " ";
    }
}