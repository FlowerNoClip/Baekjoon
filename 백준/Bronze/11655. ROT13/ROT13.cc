#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
bool isEnglish(char c){ return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');}
int main()
{
    FAST_IO;
    string str; getline(cin, str); 
    for (char &c : str) {
        if ('a' <= c && c <= 'z')      c = 'a' + ((c - 'a' + 13) % 26);
        else if ('A' <= c && c <= 'Z') c = 'A' + ((c - 'A' + 13) % 26);
    }
    cout << str;
}